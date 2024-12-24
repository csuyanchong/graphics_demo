/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: Application
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_APP_APPLICATION_H_
#define GRAPHICS_DEMO_SRC_APP_APPLICATION_H_

// Standard library
#include <string>

// Third party
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/mat3x3.hpp>
#include <glm/trigonometric.hpp>

class Application {
public:
    Application();
    ~Application();

    void init();

    void run();

    void cleanup();

private:
    /* 窗口 */
    GLFWwindow* m_window;
    /* 屏幕宽度 */
    int m_screenWidth = 1280;
    /* 屏幕高度 */
    int m_screenHeight = 720;
    /* 窗口标题 */
    std::string m_title = "Graphic Renderer Demo";

    int m_windowPositionX = 640;
    int m_windowPositionY = 200;
//    /* 屏幕清除颜色 */
//    GLfloat CLEAR_COLOR_BLACK[3] = { 0.0f, 0.0f, 0.0f };
//    GLfloat CLEAR_COLOR_GREY[3] = { 0.5f, 0.5f, 0.5f };
//    /* 屏幕深度缓存清除值 */
//    GLfloat CLEAR_DEPTH = 1.0f;

private:
    void createWindow();

    void processInput();
    void update();
    void render();
    void swapBuffer();
};


#endif //GRAPHICS_DEMO_SRC_APP_APPLICATION_H_
