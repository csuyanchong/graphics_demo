/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-25
 * File: InputManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "../../utils/LogUtil.h"

#include "InputManager.h"

bool InputManager::isKeyPressed(int key) {
    return getInstance().m_keyStates[key];
}

void InputManager::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        getInstance().m_keyStates[key] = true;
    } else if (action == GLFW_RELEASE) {
        getInstance().m_keyStates[key] = false;
    }

}

void InputManager::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        getInstance().m_buttonStates[button] = true;
    } else if (action == GLFW_RELEASE) {
        getInstance().m_buttonStates[button] = false;
    }
}

void InputManager::scrollCallback(GLFWwindow *window, double xOffset, double yOffset) {
//    LogUtil::debug(std::format("scroll data: x_{0}, y_{1}", xOffset, yOffset));
    getInstance().m_isMouseScrolling = true;
    getInstance().m_mouseScrollDelta = glm::vec2(xOffset, yOffset);
}

void InputManager::init(GLFWwindow *window) {
    getInstance().m_window = window;
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetScrollCallback(window, scrollCallback);
}

bool InputManager::isMouseButtonDown(int button) {
    return getInstance().m_buttonStates[button];
}

glm::vec2 InputManager::getMousePosition() {
    return getInstance().m_mouseCurrentPosition;
}

glm::vec2 InputManager::getMouseDelta() {
    return getInstance().m_mouseDelta;
}

void InputManager::update(float deltaTime) {
    // 处理事件
    glfwPollEvents();
    // 更新鼠标位置
    updateMousePosition();
    // 更新滚轮滑动数据
    updateMouseScrollData();
}

void InputManager::cleanUp() {
    m_buttonStates.clear();
    m_keyStates.clear();
    m_window = nullptr;
}

void InputManager::updateMousePosition() {
    double xPos, yPos;
    glfwGetCursorPos(getInstance().m_window, &xPos, &yPos);
    glm::vec2 currentPosition = glm::vec2(xPos, yPos);
    m_mouseLastPosition =  m_mouseCurrentPosition;
    m_mouseCurrentPosition = currentPosition;
    m_mouseDelta = currentPosition - m_mouseLastPosition;
}

glm::vec2 InputManager::getMouseScrollData() {
    return getInstance().m_mouseScrollDelta;
}

void InputManager::updateMouseScrollData() {
    if (!m_isMouseScrolling) {
        m_mouseScrollDelta = glm::vec2(0);
    }
    m_isMouseScrolling = false;
}
