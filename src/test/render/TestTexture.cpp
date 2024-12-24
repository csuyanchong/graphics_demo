/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-24
 * File: TestTexture
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "TestTexture.h"
#include "../../core/ResourceManager.h"

TestTexture::~TestTexture() {
    ResourceManager::getInstance().unload();
}

void TestTexture::init() {
    // 设置标题
    glfwSetWindowTitle(getWindow(), "Test Texture");
    // 注册资源路径
    ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
    ResourceManager::getInstance().registerResourcePath("textures", "textures/");
    // shader文件地址
    std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders", "texture.vert");
    std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders", "texture.frag");
    // 初始化简单的着色器
    m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

    // 创建mesh
    m_mesh = ResourceManager::getInstance().getPlaneMesh();

    // 纹理地址
    std::string texturePath = ResourceManager::getInstance().getResourcePath("textures", "brick.png");
    // 创建纹理
    m_texture = ResourceManager::getInstance().loadTexture(texturePath,
                                                           ResourceLoaderFactory::TextureLoaderType::LODEPNG);
}

void TestTexture::render() {
    // 启用shader
    m_shader->bind();

    // 启用纹理
    m_texture->bind(m_textureUnit);

    // 设置shader参数
    m_shader->setUniform("texture_sample", m_textureUnit);

    // 绘制
    m_mesh->draw();

    m_texture->unBind();
    m_shader->unBind();
}
