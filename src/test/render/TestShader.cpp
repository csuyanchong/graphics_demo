/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestShader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "TestShader.h"
#include "../../core/ResourceManager.h"

void TestShader::init() {
    // 设置标题
    glfwSetWindowTitle(getWindow(),"Test Shader");
    // 注册资源路径
    ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
    // shader文件地址
    std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders","basic.vert");
    std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders","basic.frag");
    // 初始化简单的着色器
    m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

    // 创建VAO和VBO
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f,
    };
    glGenVertexArrays(1, &m_vao);
    glGenBuffers(1, &m_vbo);

    glBindVertexArray(m_vao);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void TestShader::render() {
    m_shader->bind();
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

TestShader::~TestShader() {
    ResourceManager::getInstance().unload();
}

