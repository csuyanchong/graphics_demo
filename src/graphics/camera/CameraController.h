/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-25
 * File: CameraController
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_CAMERACONTROLLER_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_CAMERACONTROLLER_H_


#include <memory>
#include "Camera.h"

class CameraController {
public:
    explicit CameraController(std::shared_ptr<Camera>& camera) : m_camera(camera) {};
    ~CameraController();

    void update(float deltaTime);

    float m_moveSpeed = 5.0f;

    float m_mouseSensitivity = 10.f;

    float m_mouseScrollSpeed = 20.0f;

private:
    void moveCameraByKeyboard(float deltaTime);
    void rotateCamera(float deltaTime);
    void moveCameraByMouseScroll(float deltaTime, float yOffset);

    std::shared_ptr<Camera> m_camera;
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_CAMERACONTROLLER_H_
