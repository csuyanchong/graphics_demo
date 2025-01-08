/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Transform
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_SCENE_TRANSFORM_H_
#define GRAPHICS_DEMO_SRC_SCENE_TRANSFORM_H_


#include "Component.h"

#include "glm/vec3.hpp"
#include "Rotation.h"

#include <memory>

class Transform : public Component {
public:
    Transform() : m_parent(std::weak_ptr<Transform>()), m_position(0), m_scale(1) {};

    explicit Transform(std::weak_ptr<Transform> &parent) : m_parent(parent), m_position(0), m_scale(1) {};

    ~Transform() override = default;

    void setPosition(const glm::vec3 position) { m_position = position; };

    [[nodiscard]] glm::vec3 getPosition() const { return m_position; }

    void setRotation(const Rotation &rotation) { m_rotation = rotation; }

    [[nodiscard]] Rotation getRotation() const { return m_rotation; };

    void setScale(glm::vec3 scale) { m_scale = scale; }

    [[nodiscard]] glm::vec3 getScale() const { return m_scale; }

    void update(float deltaTime) override;

    void render() override;

    [[nodiscard]] glm::mat4 getLocalMatrix() const;

    [[nodiscard]] glm::mat4 getWorldMatrix() const;

private:
    glm::vec3 m_position;
    Rotation m_rotation;
    glm::vec3 m_scale;

    std::weak_ptr<Transform> m_parent;
};


#endif //GRAPHICS_DEMO_SRC_SCENE_TRANSFORM_H_
