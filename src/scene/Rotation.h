/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-30
 * File: Rotation
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_SCENE_ROTATION_H_
#define GRAPHICS_DEMO_SRC_SCENE_ROTATION_H_


#include "glm/vec3.hpp"
#include "glm/gtc/quaternion.hpp"

class Rotation {
public:
    Rotation() : m_quaternion(1, 0, 0, 0){};

    explicit Rotation(glm::vec3 eulerAngle) {
        setFromEulerAngle(eulerAngle);
    }

    explicit Rotation(glm::quat quaternion) : m_quaternion(quaternion){};

    explicit Rotation(glm::mat3 rotationMatrix) {
        setFromRotationMatrix(rotationMatrix);
    };

    void setFromEulerAngle(glm::vec3 eulerAngle) {
        m_quaternion = glm::quat(glm::radians(eulerAngle));
    }

    void setFromQuaternion(glm::quat quat) {
        m_quaternion = quat;
    }

    void setFromRotationMatrix(glm::mat3 rotationMatrix) {
        m_quaternion = glm::quat_cast(rotationMatrix);
    }

    [[nodiscard]] glm::quat getQuaternion() const{
        return m_quaternion;
    }

    /**
     * @brief 返回欧拉角。
     * @return degree.
     */
    [[nodiscard]] glm::vec3 getEulerAngle() const {
        return glm::degrees(glm::eulerAngles(m_quaternion));
    }

    [[nodiscard]] glm::mat3 getRotationMatrix33() const {
        return glm::mat3_cast(m_quaternion);
    }

    [[nodiscard]] glm::mat4 getRotationMatrix44() const {
        return glm::mat4_cast(m_quaternion);
    }
private:
    glm::quat m_quaternion{};
};


#endif //GRAPHICS_DEMO_SRC_SCENE_ROTATION_H_
