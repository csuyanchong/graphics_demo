/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: Mesh
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_MESH_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_MESH_H_


#include <vector>

#include <GL/gl3w.h>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex {
    glm::vec3 m_position;
    glm::vec3 m_normal;
    glm::vec2 m_texCoord;
};

class Mesh {
public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
    ~Mesh() = default;

    void draw() const;

private:
    /* 顶点位置 */
    std::vector<Vertex> m_vertices;
    /* 顶点索引 */
    std::vector<GLuint> m_indices;

    /* 顶点数组对象 */
    GLuint m_vao = 0;
    /* 顶点缓存对象 */
    GLuint m_vbo = 0;
    /* 索引缓存对象 */
    GLuint m_ibo = 0;
    /* 位置属性索引 */
    GLuint m_positionAttrId = 0;
    /* 法线属性索引 */
    GLuint m_normalAttrId = 1;
    /* uv坐标属性索引 */
    GLuint m_texCoordAttrId = 2;

    void setUp();
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_MESH_H_
