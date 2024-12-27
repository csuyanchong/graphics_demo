/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Material
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "Material.h"

#include <iostream>


void Material::setParameter(const std::string &name, const std::any &value) {
    m_parameters[name] = value;
}

void Material::setTexture(const std::string &name, const std::shared_ptr<Texture> &texture) {
    m_textures[name] = texture;
}

void Material::apply(){
    // 启用材质
    m_shader->bind();

    // 启用纹理
    int textureUnit = 0;
    for (const auto& [name, texture] : m_textures) {
        texture->bind(++textureUnit);
        m_shader->setUniform(name,textureUnit);
    }

    // 应用参数
    applyParameters();
}

void Material::applyParameters() {
    for (const auto& [name, value] : m_parameters) {
        if (value.type() == typeid(GLint)) {
            m_shader->setUniform(name, std::any_cast<GLint>(value));
        } else if (value.type() == typeid(GLfloat)) {
            m_shader->setUniform(name, std::any_cast<GLfloat>(value));
        } else if (value.type() == typeid(glm::vec3)) {
            m_shader->setUniform(name, std::any_cast<glm::vec3>(value));
        } else if (value.type() == typeid(glm::mat3)) {
            m_shader->setUniform(name, std::any_cast<glm::mat3>(value));
        } else if (value.type() == typeid(glm::mat4)) {
            m_shader->setUniform(name, std::any_cast<glm::mat4>(value));
        } else {
            std::cerr << "不支持的参数类型：" << name << std::endl;
        }
    }
}

Material::~Material() {
    m_textures.clear();
    m_parameters.clear();
    m_shader = nullptr;
}


