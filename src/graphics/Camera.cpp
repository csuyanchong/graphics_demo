/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-17
 * File: Camera
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "Camera.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtc/quaternion.hpp"

glm::mat4 Camera::getViewMatrix() const {
    glm::vec3 eyePos = m_position;
    glm::vec3 lookDirection = getLookDirection();
    glm::vec3 lookPoint = eyePos + lookDirection;
    return glm::lookAt(eyePos, lookPoint, m_up);
}

glm::mat4 Camera::getProjectionMatrix(float width, float height) const {
    glm::mat4 projectMatrix = glm::perspective(glm::radians(m_fov),
                                               width / height,
                                               m_nearClipPlane,
                                               m_farClipPlane);
    return projectMatrix;
}

glm::vec3 Camera::getLookDirection() const {
    auto res = glm::vec3(0, 0, -1.0);
    return res;
}
