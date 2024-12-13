#include "core/test/TestOpenGlRendering.h"
#include "core/ResourceManager.h"
#include "test/TestBasicRendering.h"
#include "test/TestMesh.h"

using namespace std;
#include <memory>

GLFWwindow* g_window;

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
    GLint textureCount = 0;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &textureCount);
}

bool shouldClose() {
    return glfwWindowShouldClose(g_window);
}

void swapBuffers() {
    glfwSwapBuffers(g_window);
}

int main() {
//    TestBasicRendering test;
//    test.Init();
//    test.render();
//    TestOpenGlRendering test{};
//    test.run();

//    ResourceManager::getInstance().loadModel();
    initWindow();

//    TestBasicRendering basicRendering;
//    basicRendering.init();

    TestMesh meshTest;
    meshTest.init();
    while (!shouldClose()) {
//        basicRendering.render();
        meshTest.render();
        swapBuffers();
        glfwPollEvents();
    }

    glfwDestroyWindow(g_window);
    glfwTerminate();
    return 0;
}