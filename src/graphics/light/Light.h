/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: Light
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_LIGHT_LIGHT_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_LIGHT_LIGHT_H_

#include "glm/vec3.hpp"
#include "glm/geometric.hpp"
#include "../Shader.h"

enum class LightType {
    DIRECTION,
    POINT,
    SPOT
};

class Light {
public:
    Light() : m_color(glm::vec3(1)), m_intensity(1.0f) {};
    Light(glm::vec3 color, float intensity) : m_color(color), m_intensity(intensity) {};
    virtual ~Light() = default;

    [[nodiscard]] glm::vec3 getColor() const { return m_color; };
    [[nodiscard]] float getIntensity() const { return m_intensity; };

    virtual void setUniforms(std::shared_ptr<Shader> &shader, int index) = 0;

protected:
    glm::vec3 m_color{glm::vec3(1)};
    float m_intensity{1.0f};
};

class PointLight : public Light {
public:
    PointLight() : Light(), m_position(glm::vec3(0)), m_rangeRadius(10) {};
    PointLight(glm::vec3 position, float rangeRadius, glm::vec3 color, float intensity) : Light(color, intensity),
                                                                                          m_position(position),
                                                                                          m_rangeRadius(rangeRadius) {};
    PointLight(glm::vec3 position, float rangeRadius) : Light(), m_position(position), m_rangeRadius(rangeRadius) {};

    [[nodiscard]] glm::vec3 getPosition() const { return m_position; };
    [[nodiscard]] float getRangeRadius() const { return m_rangeRadius; };

    void setUniforms(std::shared_ptr<Shader> &shader, int index) override {
        // TODO...
    }

private:
    // 光源位置
    glm::vec3 m_position;
    // 最大影响范围
    float m_rangeRadius;
};

class DirectionalLight : public Light {
public:
    DirectionalLight() : Light(), m_direction(glm::vec3(0, -1, 0)) {};
    explicit DirectionalLight(glm::vec3 direction) : Light(), m_direction(direction) {};
    DirectionalLight(glm::vec3 direction, glm::vec3 color, float intensity) : Light(color, intensity), m_direction
            (direction) {};

    [[nodiscard]] glm::vec3 getDirection() {
        m_direction = glm::normalize(m_direction);
        return m_direction;
    };

    void setUniforms(std::shared_ptr<Shader> &shader, int index) override {
        // TODO...
    }

private:
    // 方向
    glm::vec3 m_direction;
};

#endif //GRAPHICS_DEMO_SRC_GRAPHICS_LIGHT_LIGHT_H_
