/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Material
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_MATERIAL_MATERIAL_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_MATERIAL_MATERIAL_H_


#include <memory>
#include <string>
#include <any>
#include <vector>

#include "../Shader.h"
#include "../Texture.h"

class Material {
public:
    Material() = default;
    explicit Material(std::shared_ptr<Shader>& shader) : m_shader(shader) {};
    virtual ~Material();

    void setParameter(const std::string& name, const std::any& value);

    void setTexture(const std::string& name, const std::shared_ptr<Texture>& texture);

    /**
     * @brief 应用材质。
     */
    void apply();

    void setShader(const std::shared_ptr<Shader>& shader) { m_shader = shader; };
    [[nodiscard]] std::shared_ptr<Shader> getShader() const { return m_shader; };

protected:
    // 着色器
    std::shared_ptr<Shader> m_shader;
    // 通用参数缓存
    std::unordered_map<std::string, std::any> m_parameters;
    // 纹理集合
    std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
    // 纹理数量
    unsigned int m_countTexture = 0;

    void applyParameters();
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_MATERIAL_MATERIAL_H_
