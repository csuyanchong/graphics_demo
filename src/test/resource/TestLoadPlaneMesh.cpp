/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-24
 * File: TestLoadPlaneMesh
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "../../core/ResourceManager.h"

#include "TestLoadPlaneMesh.h"

TestLoadPlaneMesh::~TestLoadPlaneMesh() {
    ResourceManager::getInstance().unload();
}

void TestLoadPlaneMesh::init() {
    // 设置标题
    glfwSetWindowTitle(getWindow(),"Test Load Plane Mesh");
    // 注册资源路径
    ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
    // shader文件地址
    std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders", "basic.vert");
    std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders", "basic.frag");
    // 初始化简单的着色器
    m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

    // 创建mesh
    m_mesh = ResourceManager::getInstance().getPlaneMesh();
}

void TestLoadPlaneMesh::render() {
    m_shader->bind();
    m_mesh->draw();
}
