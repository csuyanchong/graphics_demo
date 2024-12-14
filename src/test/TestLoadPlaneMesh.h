/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-15
 * File: TestLoadPlaneMesh
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_TESTLOADPLANEMESH_H_
#define GRAPHICS_DEMO_SRC_TEST_TESTLOADPLANEMESH_H_

#include <GL/gl3w.h>
#include <memory>

#include "../graphics/Shader.h"
#include "../core/ResourceManager.h"

class TestLoadPlaneMesh {
public:
    void init() {
        // 注册资源路径
        ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
        // shader文件地址
        std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders","basic.vert");
        std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders","basic.frag");
        // 初始化简单的着色器
        m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

        // 创建mesh
        m_mesh = ResourceManager::getInstance().getPlaneMesh();
    }

    void render() {
        m_shader->bind();
        m_mesh->draw();
    }

private:
    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Mesh> m_mesh;
};


#endif //GRAPHICS_DEMO_SRC_TEST_TESTLOADPLANEMESH_H_
