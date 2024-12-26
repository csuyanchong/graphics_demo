/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestEnvironment
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_TESTENVIRONMENT_H_
#define GRAPHICS_DEMO_SRC_TEST_TESTENVIRONMENT_H_

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <string>

class TestEnvironment {
public:
    TestEnvironment();
    virtual ~TestEnvironment();

    void initialize();

    virtual void run();

    void close();

    [[nodiscard]] GLFWwindow* getWindow() const;

protected:
    virtual void init();

    virtual void render();

    void createWindow();

    void setClearFlag();

    /**
     * @brief 获得窗口宽高比。
     * @return aspect
     */
    [[nodiscard]] float getWindowAspect() const;

private:
    GLFWwindow* m_window;
    // 屏幕清除颜色
    GLfloat m_clearColor[4] = {0.0f, 0.0f, 0.0f, 0.0f };
    // 屏幕深度缓存清除值
    GLfloat m_clearDepth = 1.0f;
};


#endif //GRAPHICS_DEMO_SRC_TEST_TESTENVIRONMENT_H_
