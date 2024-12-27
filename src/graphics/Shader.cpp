/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: Shader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <vector>
#include <iostream>
#include <fstream>

#include <glm/gtc/type_ptr.hpp>

#include "../utils/LogUtil.h"

#include "Shader.h"

Shader::Shader(const std::string &vertPath, const std::string &fragPath) {
    m_programId = glCreateProgram();

    std::vector<ShaderInfo> shaderInfoArray;
    ShaderInfo vertInfo = {GL_VERTEX_SHADER, vertPath};
    ShaderInfo fragInfo = {GL_FRAGMENT_SHADER, fragPath};
    shaderInfoArray.push_back(vertInfo);
    shaderInfoArray.push_back(fragInfo);

    // 编译链接shader
    compileShaders(shaderInfoArray);
}

void Shader::bind() const {
    glUseProgram(m_programId);
}

void Shader::unBind() const {
    glUseProgram(0);
}

void Shader::setUniform(const std::string &id, glm::mat4 value) {
    GLint location = getUniformLocation(m_programId, id);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setUniform(const std::string &id, glm::mat3 value) {
    GLint location = getUniformLocation(m_programId, id);
    glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setUniform(const std::string &id, glm::vec3 value) {
    GLint location = getUniformLocation(m_programId, id);
    glUniform3fv(location, 1, glm::value_ptr(value));
}

void Shader::setUniform(const std::string &id, GLfloat value) {
    GLint location = getUniformLocation(m_programId, id);
    glUniform1f(location, value);
}

void Shader::setUniform(const std::string &id, GLint value) {
    GLint location = getUniformLocation(m_programId, id);
    glUniform1i(location, value);
}

std::string Shader::readShaderFromFile(const std::string &path) {
    std::string res;

    std::ifstream file;
    file.open(path);

    if (file) {
        std::string line;
        while (std::getline(file, line)) {
            res.append(line + "\n");
        }

        file.close();
    }
    else {
        // 打开文件失败
        LogUtil::error(std::format( "read file {0} failed. ", path));
    }
    return res;
}

Shader::~Shader() {
    glDeleteProgram(m_programId);
}

void Shader::compileShaders(std::vector<ShaderInfo> &shaderInfoArray) const {
    // 1.加载shader源代码，并按照类型编译.
    std::vector<GLuint*> shaders;

    for (auto const& shaderInfo : shaderInfoArray) {
        GLuint shader = glCreateShader(shaderInfo.m_type);
        shaders.push_back(&shader);
        std::string sourceCode = readShaderFromFile(shaderInfo.m_filePath);
        const char* stringSource = sourceCode.c_str();
        // m_shader 填充源码
        glShaderSource(shader, 1, &stringSource, nullptr);
        // 编译
        glCompileShader(shader);
        // 查看编译结果
        GLint resShaderCompile = GL_TRUE;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &resShaderCompile);
        if (resShaderCompile == GL_FALSE) {
            // 处理编译失败
            LogUtil::error(std::format( "shader compile failed, file path: {0} ", shaderInfo.m_filePath));
            GLsizei logLength = 0;
            GLchar message[1024];
            glGetShaderInfoLog(shader, 1024, &logLength, message);
            LogUtil::error(std::format( "shader info log: {0} ", message));
            // TODO...写入日志
        }
        // 将shader和program绑定
        glAttachShader(m_programId, shader);
    }

    // 2.链接编译好的shader到program
    glLinkProgram(m_programId);
    // 查看链接结果
    GLint resProgramLink = GL_TRUE;
    glGetProgramiv(m_programId, GL_COMPILE_STATUS, &resProgramLink);
    if (resProgramLink == GL_FALSE) {
        // 处理链接失败
        LogUtil::error(std::format( "shader program link failed. "));
        GLsizei logLength = 0;
        GLchar message[1024];
        glGetProgramInfoLog(m_programId, 1024, &logLength, message);
        LogUtil::error(std::format( "shader program info log: {0} ", message));
    }

    // 3.删除shader对象
    for(auto shader : shaders) {
        glDeleteShader(*shader);
    }
}

int Shader::getUniformLocation(GLuint programId, const std::string &name) {
    if(m_uniformLocationCache.find(name) != m_uniformLocationCache.end()) {
        return m_uniformLocationCache[name];
    }

    GLint location = glGetUniformLocation(m_programId, name.c_str());
    if (location == -1) {
        LogUtil::error(std::format( "get shader uniform location {0} failed. ", name));
    }
    m_uniformLocationCache[name] = location;
    return location;
}
