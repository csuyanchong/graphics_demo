/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: Mesh
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices) : m_vertices(vertices), m_indices(indices) {
    setUp();
}

void Mesh::draw() const{
    // 绑定顶点缓存vao
    glBindVertexArray(m_vao);

    // 启用相关属性attribute
    glEnableVertexAttribArray(m_positionAttrId);
    glEnableVertexAttribArray(m_normalAttrId);
    glEnableVertexAttribArray(m_texCoordAttrId);

    // 绘制
    glDrawElements(GL_TRIANGLES, (GLsizei)m_indices.size(), GL_UNSIGNED_INT, nullptr);
}

void Mesh::setUp() {
    // 创建OpenGL缓存
    // 创建vao
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    // 创建索引缓存
    glGenBuffers(1, &m_ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(GLuint), m_indices.data(), GL_STATIC_DRAW);

    // 创建顶点缓存
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_STATIC_DRAW);

    // 向vao解释attribute对应的缓存内容

    // 偏移参数设置
    GLsizei strideVertex = sizeof(Vertex);
    GLintptr vertexPositionOffset = 0 * sizeof(GLfloat);
    GLintptr vertexNormalOffset = 3 * sizeof(GLfloat);
    GLintptr vertexTexCoordOffset = 6 * sizeof(GLfloat);

    // 顶点位置属性
    glVertexAttribPointer(m_positionAttrId, 3, GL_FLOAT, GL_FALSE, strideVertex, (GLvoid*)vertexPositionOffset);

    // 顶点法线属性
    glVertexAttribPointer(m_normalAttrId, 3, GL_FLOAT, GL_FALSE, strideVertex, (GLvoid*)vertexNormalOffset);

    // uv坐标属性
    glVertexAttribPointer(m_texCoordAttrId, 2, GL_FLOAT, GL_FALSE, strideVertex, (GLvoid*)vertexTexCoordOffset);

    // 创建完先关闭，绘制前再启用
    glDisableVertexAttribArray(m_positionAttrId);
    glDisableVertexAttribArray(m_normalAttrId);
    glDisableVertexAttribArray(m_texCoordAttrId);
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &m_vbo);
    glDeleteBuffers(1, &m_ibo);
    glDeleteVertexArrays(1, &m_vao);
}

