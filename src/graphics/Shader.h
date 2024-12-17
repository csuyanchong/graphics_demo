/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: Shader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_SHADER_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_SHADER_H_


#include <string>
#include <memory>
#include <unordered_map>
#include <vector>

#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

#include <gl/gl3w.h>

typedef struct {
    const GLenum m_type; // shader类型
    const std::string m_filePath; // shader源代码路径
} ShaderInfo;

class Shader {
public:
    Shader(const std::string& vertPath, const std::string& fragPath);
    ~Shader();

    // 启用当前shader
    void bind() const;
    // 解绑当前shader
    void unBind() const;

    // 查询并修改uniform变量
    void setUniform(const std::string& id, glm::mat4 value);
    void setUniform(const std::string& id, glm::mat3 value);
    void setUniform(const std::string& id, glm::vec3 value);
    void setUniform(const std::string& id, GLfloat value);
    void setUniform(const std::string& id, GLint value);

private:
    // 着色器程序id
    GLuint m_programId;

    // 缓存uniform变量的位置
    std::unordered_map<std::string, GLint> m_uniformLocationCache;

    // 辅助方法
    static std::string readShaderFromFile(const std::string& path);
    void compileShaders(std::vector<ShaderInfo> &shaderInfoArray) const;
    int getUniformLocation(GLuint programId, const std::string& name);
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_SHADER_H_
