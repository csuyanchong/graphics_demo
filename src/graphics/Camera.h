/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-17
 * File: Camera
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_H_


#include "glm/ext/matrix_float4x4.hpp"

class Camera {
public:
    Camera() : m_position(glm::vec3(0)), m_up(glm::vec3(0, 1.0f, 0)), m_lookFromPoint(glm::vec3(0)), m_lookToPoint(glm::vec3(0, 0, -1.0f)) {};

    [[nodiscard]] glm::mat4 getViewMatrix() const;

    [[nodiscard]] glm::mat4 getProjectionMatrix(float width, float height) const;

    [[nodiscard]] glm::vec3 getLookDirection() const;

    void setPosition(glm::vec3 position) { m_position = position; };

private:
    // 当前位置
    glm::vec3 m_position;
    // 上方向
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_look;
    glm::vec3 m_worldUp;

    // 观察方向起点
    glm::vec3 m_lookFromPoint;
    // 观察方向终点
    glm::vec3 m_lookToPoint;

    float m_fov = 45;
    float m_nearClipPlane = 0.1;
    float m_farClipPlane = 100;
    float m_aspect = 1920.0 / 1080;
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_CAMERA_H_
