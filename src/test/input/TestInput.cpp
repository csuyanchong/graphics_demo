/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-25
 * File: TestInput
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */
#include "../../utils/LogUtil.h"
#include "../../core/ResourceManager.h"
#include "../../graphics/input/InputManager.h"
#include "TestInput.h"

TestInput::~TestInput() {
    ResourceManager::getInstance().unload();
    InputManager::getInstance().cleanUp();
}

void TestInput::init() {
    // 启用垂直同步（启用为1，关闭为0）
    glfwSwapInterval(1);
    // 设置标题
    glfwSetWindowTitle(getWindow(), "Test Input");
    // 注册资源路径
    ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
    ResourceManager::getInstance().registerResourcePath("models", "models/");
    ResourceManager::getInstance().registerResourcePath("textures", "textures/");

    // shader文件地址
    std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders","camera.vert");
    std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders","camera.frag");
    // 初始化简单的着色器
    m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

    // 模型文件地址
    std::string modelPath = ResourceManager::getInstance().getResourcePath("models","cube_numbers.obj");
    // 加载模型
    m_model = ResourceManager::getInstance().loadModel(modelPath,
                                                       ResourceLoaderFactory::ModelLoaderType::ASSIMP);
    // 创建材质
    m_material = std::make_shared<Material>(m_shader);

    // 赋予纹理
    // 纹理地址
    std::string texturePath = ResourceManager::getInstance().getResourcePath("textures","cube_diffuse.png");
    // 创建纹理
    m_texture = ResourceManager::getInstance().loadTexture(texturePath, ResourceLoaderFactory::TextureLoaderType::LODEPNG);
    m_material->setTexture("material_diffuse", m_texture);

    // 创建相机
    glm::vec3 cameraPosition = glm::vec3(3.4, 1.2, 2.9);
    float cameraAspect = getWindowAspect();
    m_camera = std::make_shared<Camera>(cameraPosition, cameraAspect);

    // 创建相机控制器
    m_cameraController = std::make_shared<CameraController>(m_camera);

    // 初始化输入管理器
    InputManager::init(getWindow());
    m_camera->setYaw(50);
    m_camera->setPitch(-9);
}

void TestInput::render() {
    setClearFlag();
    // 计算参数
    auto modelMatrix= glm::mat4(1.0f);
    auto viewMatrix = m_camera->getViewMatrix();
    auto projectionMatrix = m_camera->getProjectionMatrix();
    auto mvp = projectionMatrix * viewMatrix * modelMatrix;

    m_material->setParameter("u_mvp", mvp);
    m_material->apply();
    m_model->render();
}

void TestInput::run() {
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

void TestInput::processInput(float deltaTime) {
    InputManager::getInstance().update(deltaTime);
}

void TestInput::update(float deltaTime) {
    // 更新相机
    m_cameraController->update(deltaTime);
    // 更新场景物体
}

float TestInput::getDeltaTime() {
    m_currentTime = glfwGetTime();
    auto deltaTime = static_cast<float>(m_currentTime - m_lastTime);
    m_lastTime = m_currentTime;
    return deltaTime;
}

