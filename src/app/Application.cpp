/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: Application
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <iostream>
#include "../utils/LogUtil.h"

#include "Application.h"

Application::Application() : m_window(nullptr){
    LogUtil::info("App start...");
    // 初始化
    init();
}

Application::~Application() {
    cleanup();
    LogUtil::info("App end.");
}

void Application::init() {
    LogUtil::info("App init.");
    // 创建窗口
    createWindow();
//    // 创建场景
//    createScene();
//    // 创建渲染管线
//    createRenderPipeline();
//    // 绑定输入
//    bindInput();
//    // 创建framebuffer
//    createFrameBuffer();
    LogUtil::info("App init done.");
}

void Application::run() {
    while (!glfwWindowShouldClose(m_window)) {
        processInput();
        update();
        render();
        swapBuffer();
    }
}

void Application::cleanup() {
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Application::createWindow() {
    // 初始化glfw
    if (glfwInit() == GLFW_FALSE) {
        std::cout << "glfw library 初始化失败！" << std::endl;
        exit(EXIT_FAILURE);
    }
    // 设置MSAA
    //glfwWindowHint(GLFW_SAMPLES, 4);
    // 初始化窗口位置
    glfwWindowHint(GLFW_POSITION_X, m_windowPositionX);
    glfwWindowHint(GLFW_POSITION_Y, m_windowPositionY);
    // 创建窗口
    m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, m_title.c_str(), nullptr, nullptr);
    //glfwSetWindowPos(window, SCREEN_POSITION_X, SCREEN_POSITION_Y);
    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, this);
    // 初始化gl3w
    gl3wInit();
    // 查询显卡支持的最大纹理单元数量
    GLint textureCount = 0;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &textureCount);
}

void Application::processInput() {
    glfwPollEvents();
}

void Application::update() {

}

void Application::render() {

}

void Application::swapBuffer() {
    glfwSwapBuffers(m_window);
}
