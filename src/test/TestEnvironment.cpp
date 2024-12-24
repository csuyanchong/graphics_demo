/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestEnvironment
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <iostream>
#include "TestEnvironment.h"

TestEnvironment::TestEnvironment() : m_window(nullptr) {
}

TestEnvironment::~TestEnvironment() {
    close();
}

void TestEnvironment::createWindow() {
    // 初始化glfw
    if (glfwInit() == GLFW_FALSE) {
        std::cout << "glfw library 初始化失败！" << std::endl;
        exit(EXIT_FAILURE);
    }
    // 设置MSAA
    //glfwWindowHint(GLFW_SAMPLES, 4);
    // 初始化窗口位置
    glfwWindowHint(GLFW_POSITION_X, 200);
    glfwWindowHint(GLFW_POSITION_Y, 200);
    // 创建窗口
    m_window= glfwCreateWindow(1920, 1080, "Test Environment", nullptr, nullptr);
    //glfwSetWindowPos(window, SCREEN_POSITION_X, SCREEN_POSITION_Y);
    glfwMakeContextCurrent(m_window);
    // glfwSetWindowUserPointer(window, this);
    // 初始化gl3w
    gl3wInit();
    // 查询显卡支持的最大纹理单元数量
    //GLint textureCount = 0;
    //glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &textureCount);
}

void TestEnvironment::initialize() {
    createWindow();
    init();
}

void TestEnvironment::init() {
    // the init logic
}


void TestEnvironment::run() {
    while (!glfwWindowShouldClose(m_window)) {
        setClearFlag();
        render();
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

void TestEnvironment::close() {
    if (m_window) {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}


GLFWwindow *TestEnvironment::getWindow() const {
    return m_window;
}

void TestEnvironment::render() {
    // the frame render logic
}

void TestEnvironment::setClearFlag() {
    // 清除颜色和深度缓冲
    glClearBufferfv(GL_COLOR, 0, m_clearColor);
    glClearBufferfv(GL_DEPTH, 0, &m_clearDepth);

    // 开启背面剔除
    //glEnable(GL_CULL_FACE);
    //glFrontFace(GL_CCW);
    //glCullFace(GL_BACK);

    // 隐藏面消除
    glEnable(GL_DEPTH_TEST);
    //// 开启MSAA
    //glEnable(GL_MULTISAMPLE);
}



