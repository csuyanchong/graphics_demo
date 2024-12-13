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

#include <GL/gl.h>


void Material::setParameter(const std::string &name, const std::any &value) {
    m_parameters[name] = value;
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
