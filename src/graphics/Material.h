/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Material
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_MATERIAL_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_MATERIAL_H_


#include <memory>
#include <string>
#include <any>

#include "Shader.h"

class Material {
public:
    Material() = default;
    Material(std::shared_ptr<Shader>& shader) : m_shader(shader) {};

    void setParameter(const std::string& name, const std::any& value);
    void applyParameters();

    void setShader(const std::shared_ptr<Shader>& shader) { m_shader = shader; };
    std::shared_ptr<Shader> getShader() const { return m_shader; };

private:
    std::shared_ptr<Shader> m_shader;
    // 通用参数缓存
    std::unordered_map<std::string, std::any> m_parameters;
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_MATERIAL_H_
