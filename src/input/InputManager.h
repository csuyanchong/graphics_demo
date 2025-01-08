/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-25
 * File: InputManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_INPUT_INPUTMANAGER_H_
#define GRAPHICS_DEMO_SRC_INPUT_INPUTMANAGER_H_

#include "GLFW/glfw3.h"
#include <unordered_map>
#include "glm/vec2.hpp"

class InputManager {
public:
    static InputManager &getInstance() {
        static InputManager instance;
        return instance;
    }

    InputManager(const InputManager &) = delete;

    InputManager &operator=(const InputManager &) = delete;

    static bool isKeyPressed(int key);

    static bool isMouseButtonDown(int button);

    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

    static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);

    static void init(GLFWwindow *window);

    static glm::vec2 getMousePosition();

    static glm::vec2 getMouseDelta();

    static glm::vec2 getMouseScrollData();

    void update(float deltaTime);

    void cleanUp();
private:
    InputManager() : m_window(nullptr) {};

    void updateMousePosition();
    void updateMouseScrollData();

    std::unordered_map<int, bool> m_keyStates{};
    std::unordered_map<int, bool> m_buttonStates{};

    glm::vec2 m_mouseCurrentPosition{};
    glm::vec2 m_mouseLastPosition{};
    glm::vec2 m_mouseDelta{};

    glm::vec2 m_mouseScrollDelta{};
    bool m_isMouseScrolling = false;
    GLFWwindow *m_window;
};


#endif //GRAPHICS_DEMO_SRC_INPUT_INPUTMANAGER_H_
