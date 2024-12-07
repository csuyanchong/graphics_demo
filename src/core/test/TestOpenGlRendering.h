/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: TestOpenGlRendering
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_TEST_TESTOPENGLRENDERING_H_
#define GRAPHICS_DEMO_SRC_CORE_TEST_TESTOPENGLRENDERING_H_


#include <iostream>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>


class TestOpenGlRendering {
public:
    void run() {
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
         m_window= glfwCreateWindow(1920, 1080, "graphics_demo", nullptr, nullptr);
        //glfwSetWindowPos(window, SCREEN_POSITION_X, SCREEN_POSITION_Y);
        glfwMakeContextCurrent(m_window);
        // glfwSetWindowUserPointer(window, this);
        // 初始化gl3w
        gl3wInit();
        // 查询显卡支持的最大纹理单元数量
        GLint textureCount = 0;
        glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &textureCount);

        while(!glfwWindowShouldClose(m_window)) {
            draw();
            glfwSwapBuffers(m_window);
            glfwPollEvents();
        }


    }

    ~TestOpenGlRendering() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

private:
    void draw() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);

        glClearColor(0, 0, 0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

    }

    GLFWwindow* m_window;
};


#endif //GRAPHICS_DEMO_SRC_CORE_TEST_TESTOPENGLRENDERING_H_
