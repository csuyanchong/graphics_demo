/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Transform
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "Transform.h"

void Transform::update(float deltaTime) {

}

void Transform::render() {

}

glm::mat4 Transform::getLocalMatrix() const {
    return glm::translate(glm::mat4(1), m_position) *
            m_rotation.getRotationMatrix44() *
            glm::scale(glm::mat4(1),m_scale);
}

glm::mat4 Transform::getWorldMatrix() const {
    if (auto parent = m_parent.lock()) {
        return parent->getWorldMatrix() * getLocalMatrix();
    } else {
        return getLocalMatrix();
    }
}

