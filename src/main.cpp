#include "core/test/TestOpenGlRendering.h"
#include "core/ResourceManager.h"
#include "test/TestBasicRendering.h"
#include "test/TestMesh.h"
#include "test/TestLoadPlaneMesh.h"
#include "test/TestTexture.h"

using namespace std;
#include <memory>

// 窗口
GLFWwindow* g_window;
// 屏幕清除颜色
GLfloat g_clearColor[4] = {0.0f, 0.0f, 0.0f, 0.0f };
// 屏幕深度缓存清除值
GLfloat g_clearDepth = 1.0f;

void initWindow() {
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
    g_window= glfwCreateWindow(1920, 1080, "graphics_demo", nullptr, nullptr);
    //glfwSetWindowPos(window, SCREEN_POSITION_X, SCREEN_POSITION_Y);
    glfwMakeContextCurrent(g_window);
    // glfwSetWindowUserPointer(window, this);
    // 初始化gl3w
    gl3wInit();
    // 查询显卡支持的最大纹理单元数量
    //GLint textureCount = 0;
    //glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &textureCount);
}

bool shouldClose() {
    return glfwWindowShouldClose(g_window);
}

void swapBuffers() {
    glfwSwapBuffers(g_window);
}

void setClearFlag() {
    // 清除颜色和深度缓冲
    glClearBufferfv(GL_COLOR, 0, g_clearColor);
    glClearBufferfv(GL_DEPTH, 0, &g_clearDepth);

    // 开启背面剔除
    //glEnable(GL_CULL_FACE);
    //glFrontFace(GL_CCW);
    //glCullFace(GL_BACK);

    // 隐藏面消除
    glEnable(GL_DEPTH_TEST);
    //// 开启MSAA
    //glEnable(GL_MULTISAMPLE);
}

int main() {
//    TestBasicRendering test;
//    test.Init();
//    test.render();
//    TestOpenGlRendering test{};
//    test.run();

//    ResourceManager::getInstance().loadModel();
    initWindow();

//    TestBasicRendering test;
//    test.init();

//    TestMesh test;
//    test.init();

//    // 测试加载平面网格
//    TestLoadPlaneMesh test;
//    test.init();
    TestTexture test;
    test.init();

    while (!shouldClose()) {
        setClearFlag();
        test.render();
        swapBuffers();
        glfwPollEvents();
    }

    glfwDestroyWindow(g_window);
    glfwTerminate();
    return 0;
}