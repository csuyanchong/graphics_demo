/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-25
 * File: CameraController
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "../../input/InputManager.h"
#include "../../utils/LogUtil.h"
#include "CameraController.h"

void CameraController::update(float deltaTime) {
    // 鼠标右键按下，控制镜头移动和旋转
    if (InputManager::isMouseButtonDown(GLFW_MOUSE_BUTTON_RIGHT)) {
        // 相机移动
        moveCameraByKeyboard(deltaTime);
        // 相机旋转
        rotateCamera(deltaTime);
    }
//    LogUtil::debug(std::format("camera position: x_{0}, y_{1}, z_{2}",
//                               m_camera->getPosition().x,
//                               m_camera->getPosition().y,
//                               m_camera->getPosition().z));
//
//    LogUtil::debug(std::format("rotate data: yaw_{0}, pitch_{1}", m_camera->getYaw(), m_camera->getPitch()));

    // 鼠标滚轮
    if (InputManager::getMouseScrollData().y != 0) {
        // 控制镜头拉近拉远
        moveCameraByMouseScroll(deltaTime, InputManager::getMouseScrollData().y);
    }
}

void CameraController::moveCameraByKeyboard(float deltaTime) {
    glm::vec3 forwardDir(.0f);
    glm::vec3 rightDir(.0f);
    if (InputManager::isKeyPressed(GLFW_KEY_W)) {
        forwardDir = m_camera->getLookDirection() * m_moveSpeed * deltaTime;
    }
    if (InputManager::isKeyPressed(GLFW_KEY_S)) {
        forwardDir = -1.0f * m_camera->getLookDirection() * m_moveSpeed * deltaTime;
    }
    if (InputManager::isKeyPressed(GLFW_KEY_A)) {
        rightDir = -1.0f * m_camera->getRightDirection() * m_moveSpeed * deltaTime;
    }
    if (InputManager::isKeyPressed(GLFW_KEY_D)) {
        rightDir = m_camera->getRightDirection() * m_moveSpeed * deltaTime;
    }

    glm::vec3 positionNew = m_camera->getPosition() + forwardDir + rightDir;
    m_camera->setPosition(positionNew);
}

void CameraController::rotateCamera(float deltaTime) {
    glm::vec2 mouseDelta = InputManager::getMouseDelta();
    //LogUtil::debug(std::format("mouse delta x:{0}, y:{1}", mouseDelta.x, mouseDelta.y));
    float yaw = m_camera->getYaw() - mouseDelta.x * m_mouseSensitivity * deltaTime;
    m_camera->setYaw(yaw);

    float pitch = m_camera->getPitch() - mouseDelta.y * m_mouseSensitivity * deltaTime;
    m_camera->setPitch(pitch);
}

void CameraController::moveCameraByMouseScroll(float deltaTime, float yOffset) {
    float scrollDeltaY = InputManager::getMouseScrollData().y;
    glm::vec3 dir = m_camera->getLookDirection() * scrollDeltaY;
    glm::vec3 forwardDir = dir * m_mouseScrollSpeed * deltaTime;
    glm::vec3 positionNew = m_camera->getPosition() + forwardDir;
    m_camera->setPosition(positionNew);
}

CameraController::~CameraController() {
    m_camera = nullptr;
}
