/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-17
 * File: Camera
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */


#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include "Camera.h"

glm::mat4 Camera::getViewMatrix() {
    glm::vec3 lookDir = getLookDirection();
    glm::vec3 lookPoint = m_position + lookDir;
    return glm::lookAt(m_position, lookPoint, getUpDirection());
}

glm::mat4 Camera::getProjectionMatrix() const {
    glm::mat4 projectMatrix = glm::perspective(glm::radians(m_fov),
                                               m_aspect,
                                               m_nearClipPlane,
                                               m_farClipPlane);
    return projectMatrix;
}

glm::vec3 Camera::getLookDirection() {
    // 根据旋转重新计算观察方向
    glm::mat3 rotationMatrix = glm::eulerAngleYX(glm::radians(m_yaw), glm::radians(m_pitch));
    glm::vec3 lookDir = rotationMatrix * m_lookDefault;
    lookDir = glm::normalize(lookDir);
    m_look = lookDir;
    return lookDir;
}

glm::vec3 Camera::getUpDirection() {
    // 根据旋转重新计算观察方向
    glm::mat3 rotationMatrix = glm::eulerAngleYX(glm::radians(m_yaw), glm::radians(m_pitch));
    glm::vec3 upDir = rotationMatrix * m_worldUp;
    upDir = glm::normalize(upDir);
    m_up = upDir;
    return upDir;
}

glm::vec3 Camera::getRightDirection() {
    // 根据旋转重新计算观察方向
    glm::mat3 rotationMatrix = glm::eulerAngleYX(glm::radians(m_yaw), glm::radians(m_pitch));
    glm::vec3 rightDir = rotationMatrix * m_rightDefault;
    rightDir = glm::normalize(rightDir);
    m_right = rightDir;
    return rightDir;
}

glm::vec3 Camera::getPosition() const {
    return m_position;
}

float Camera::getYaw() const {
    return m_yaw;
}

void Camera::setYaw(float yaw) {
    m_yaw = yaw;
}

float Camera::getPitch() const {
    return m_pitch;
}

void Camera::setPitch(float pitch) {
    m_pitch = pitch;
}

