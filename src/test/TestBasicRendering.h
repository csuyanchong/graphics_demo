/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-10
 * File: TestBasicRendering
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_TESTBASICRENDERING_H_
#define GRAPHICS_DEMO_SRC_TEST_TESTBASICRENDERING_H_


#include <GL/gl3w.h>
#include <memory>

#include "../graphics/Shader.h"
#include "../core/ResourceManager.h"

class TestBasicRendering {
public:
    void init() {
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

    void render() {
        m_shader->bind();
        glBindVertexArray(m_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

private:
    GLuint m_vao, m_vbo;
    std::shared_ptr<Shader> m_shader;

};


#endif //GRAPHICS_DEMO_SRC_TEST_TESTBASICRENDERING_H_
