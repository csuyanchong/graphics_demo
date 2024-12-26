/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-17
 * File: Camera
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_CAMERA_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_CAMERA_H_


#include "glm/ext/matrix_float4x4.hpp"
//#include "CameraController.h"

class Camera {
public:
    explicit Camera(float aspect) : m_position(glm::vec3(0)), m_fov(45.f), m_nearClipPlane(0.1f), m_farClipPlane(100.f),
                           m_aspect(aspect) {};

    explicit Camera(glm::vec3 position, float aspect) : m_position(position), m_fov(45.f), m_nearClipPlane(0.1f),
                                                        m_farClipPlane(100.f),
                                                        m_aspect(aspect) {};

    Camera(glm::vec3 position, float fov, float near, float far, float aspect) :
            m_position(position), m_fov(), m_nearClipPlane(near), m_farClipPlane(far), m_aspect(aspect) {};

    [[nodiscard]] glm::mat4 getViewMatrix();

    [[nodiscard]] glm::mat4 getProjectionMatrix() const;

    glm::vec3 getLookDirection();
    glm::vec3 getUpDirection();
    glm::vec3 getRightDirection();

    [[nodiscard]] glm::vec3 getPosition() const;
    void setPosition(glm::vec3 position) { m_position = position; };

    [[nodiscard]] float getYaw() const;
    void setYaw(float yaw);

    [[nodiscard]] float getPitch() const;
    void setPitch(float pitch);

private:

    // 位置
    glm::vec3 m_position;
    // y轴旋转
    float m_yaw = 0.f;
    // x轴旋转
    float m_pitch = 0.f;
    // 上
    glm::vec3 m_up = glm::vec3(0, 1, 0);
    // 右
    glm::vec3 m_right = glm::vec3(1, 0, 0);
    // 前
    glm::vec3 m_look = glm::vec3(0, 0, -1);
    // 世界上
    const glm::vec3 m_worldUp = glm::vec3(0, 1, 0);
    // 默认前方
    const glm::vec3 m_lookDefault = glm::vec3(0, 0, -1);
    // 默认右方
    const glm::vec3 m_rightDefault = glm::vec3(1, 0, 0);
    // field of view angle in y direction
    float m_fov;
    float m_nearClipPlane;
    float m_farClipPlane;
    float m_aspect;
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_CAMERA_H_
