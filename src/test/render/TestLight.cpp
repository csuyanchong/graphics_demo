/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-26
 * File: TestLight
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "../../core/ResourceManager.h"
#include "../../input/InputManager.h"
#include "glm/ext/matrix_transform.hpp"
#include "TestLight.h"


TestLight::~TestLight() {
    m_directionalLight = nullptr;
    m_cameraController = nullptr;
    m_camera = nullptr;
    m_texture = nullptr;
    m_material = nullptr;
    m_model = nullptr;
    m_shader = nullptr;
    ResourceManager::getInstance().unload();
    InputManager::getInstance().cleanUp();
}

void TestLight::run() {
    while (!glfwWindowShouldClose(getWindow())) {
        float deltaTime = getDeltaTime();
        m_fps = 1.0f / deltaTime;
//        LogUtil::debug(std::format("fps: {}", m_fps));
        processInput(deltaTime);
        update(deltaTime);
        render();
        glfwSwapBuffers(getWindow());
    }
}

void TestLight::init() {
    // 启用垂直同步（启用为1，关闭为0）
    glfwSwapInterval(1);
    // 设置标题
    glfwSetWindowTitle(getWindow(), "Test Light");
    // 注册资源路径
    ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
    ResourceManager::getInstance().registerResourcePath("models", "models/");

    // shader文件地址
    std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders", "blinn_phong.vert");
    std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders", "blinn_phong.frag");
    // 初始化简单的着色器
    m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

    // 模型文件地址
    std::string modelPath = ResourceManager::getInstance().getResourcePath("models", "teapot.obj");
    // 加载模型
    m_model = ResourceManager::getInstance().loadModel(modelPath,
                                                       ResourceLoaderFactory::ModelLoaderType::ASSIMP);
    // 创建blinn-phong材质
    // 参数 ka, kd, ks, alpha
    m_material = std::make_shared<BlinnPhongMaterial>(m_materialKa, m_materialKd, m_materialKs, m_materialAlpha,
                                                      m_shader);

    // 创建相机
    glm::vec3 cameraPosition{0, 1, 3};
//    glm::vec3 cameraPosition = glm::vec3(0.3, 1, 2.5);
    float cameraAspect = getWindowAspect();
    m_camera = std::make_shared<Camera>(cameraPosition, cameraAspect);

    // 创建相机控制器
    m_cameraController = std::make_shared<CameraController>(m_camera);

    // 初始化输入管理器
    InputManager::init(getWindow());
//    m_camera->setYaw(6.5);
    m_camera->setPitch(-21);

    // 创建平行光
    m_directionalLight = std::make_shared<DirectionalLight>(glm::vec3(-1, -1, -1),
                                                            glm::vec3(1, 1, 1),
                                                            1.0f);

}

void TestLight::render() {
    setClearFlag();
    // 计算并传递参数
    preCompute();
    // 应用参数
    m_material->apply();
    m_model->render();
}

float TestLight::getDeltaTime() {
    m_currentTime = glfwGetTime();
    auto deltaTime = static_cast<float>(m_currentTime - m_lastTime);
    m_lastTime = m_currentTime;
    return deltaTime;
}

void TestLight::processInput(float deltaTime) {
    InputManager::getInstance().update(deltaTime);
}

void TestLight::update(float deltaTime) {
    // 更新相机
    m_cameraController->update(deltaTime);
    // 更新场景物体
}

void TestLight::preCompute() {
    // 计算mv, mvp, mvNormal
    auto modelMatrix = glm::mat4(1.0f);
    auto viewMatrix = m_camera->getViewMatrix();
    auto projectionMatrix = m_camera->getProjectionMatrix();
    auto mvp = projectionMatrix * viewMatrix * modelMatrix;
    auto mv = viewMatrix * modelMatrix;

    // 法线在view空间的变换
    glm::mat4x4 modelViewForNormal44 = glm::transpose(glm::inverse(mv));
    glm::mat3 matNormal = modelViewForNormal44;

    m_material->setParameter("u_mvp", mvp);
    m_material->setParameter("u_mv", mv);
    m_material->setParameter("u_mat_normal", matNormal);

    // 计算light在view空间的方向。光线方向变换到view空间，不考虑平移，所以3*3矩阵就够了
    glm::vec3 dirLight = m_directionalLight->getDirection();
    glm::mat3 modelLight{1.0};
//    glm::mat3 modelLight = glm::rotate(glm::mat4(1.0f), glm::radians(lightRotationSpeed), glm::vec3(1.0f, 0, -1.0f));
    glm::mat3 viewMatrix3 = viewMatrix;

    glm::vec3 dirLightCompute = viewMatrix3 * modelLight * dirLight;
    dirLight = glm::normalize(dirLightCompute);
    m_material->setParameter("u_light_direction", dirLight);

    // color and intensity
    m_material->setParameter("u_light_color", m_directionalLight->getColor());
    m_material->setParameter("u_light_intensity", m_directionalLight->getIntensity());
}
