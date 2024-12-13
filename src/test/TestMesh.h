/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-12
 * File: TestMesh
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_TESTMESH_H_
#define GRAPHICS_DEMO_SRC_TEST_TESTMESH_H_

#include <iostream>

#include <glm/ext/matrix_transform.hpp>
#include "../core/ResourceManager.h"
#include "../graphics/Mesh.h"

class TestMesh {
public:
    void init() {
        // 注册资源路径
        ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
        // shader文件地址
        std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders","basic.vert");
        std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders","basic.frag");
        // 初始化简单的着色器
        m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

        // 创建网格
        m_mesh = createMesh();
    };

    void render() {
        m_shader->bind();
        m_mesh->draw();
    };

private:
    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Mesh> m_mesh;

    std::shared_ptr<Mesh> createMesh() {
        Vertex vt0 = {};
        vt0.m_position = glm::vec3( -0.5f, -0.5f, 0.0f);
        Vertex vt1 = {};
        vt1.m_position = glm::vec3( 0.5f, -0.5f, 0.0f);
        Vertex vt2 = {};
        vt2.m_position = glm::vec3( 0.0f,  0.5f, 0.0f);

        std::vector<Vertex> vertices {vt0, vt1, vt2};
        std::vector<GLuint> indices {0, 1, 2};
        return std::make_shared<Mesh>(vertices, indices);
    }
};


#endif //GRAPHICS_DEMO_SRC_TEST_TESTMESH_H_
