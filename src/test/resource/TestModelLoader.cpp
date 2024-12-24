/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-23
 * File: TestModelLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "../../core/ResourceManager.h"
#include "TestModelLoader.h"

TestModelLoader::~TestModelLoader() {
    ResourceManager::getInstance().unload();
}

void TestModelLoader::init() {
    // 设置标题
    glfwSetWindowTitle(getWindow(), "Test Model Loader");
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
    m_camera = std::make_shared<Camera>();
    m_camera->setPosition(glm::vec3(1, 1, 4));
}

void TestModelLoader::render() {
    // 计算参数
    auto modelMatrix= glm::mat4(1.0f);
    auto viewMatrix = m_camera->getViewMatrix();
    auto projectionMatrix = m_camera->getProjectionMatrix(1920, 1080);
    auto mvp = projectionMatrix * viewMatrix * modelMatrix;

    m_material->setParameter("u_mvp", mvp);
    m_material->apply();
    m_model->render();
}
