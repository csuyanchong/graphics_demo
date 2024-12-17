/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-16
 * File: AssimpModelLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "AssimpModelLoader.h"

#include <iostream>

std::shared_ptr<Model> AssimpModelLoader::loadModel(const std::string &path) {
    auto model = std::make_shared<Model>();

    // 读取并加载模型文件
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate);
    if (nullptr == scene) {
        std::cerr << importer.GetErrorString() << std::endl;
        exit(EXIT_FAILURE);
    }

    model->m_directory = path.substr(0, path.find_last_of("/\\"));

    // 处理OpenGL节点
    processNode(scene->mRootNode, scene, model);

    return model;
}

void AssimpModelLoader::processNode(aiNode *node, const aiScene *scene, std::shared_ptr<Model>& model) {
    for (unsigned i = 0; i < node->mNumMeshes; i++) {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        model->addMesh(processMesh(mesh, scene));
    }

    for (unsigned i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene, model);
    }
}

std::shared_ptr<Mesh> AssimpModelLoader::processMesh(aiMesh *mesh, const aiScene *scene) {
    // Data to
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    // Walk through each of the mesh's vertices
    for (GLuint i = 0; i < mesh->mNumVertices; i++) {
        Vertex vertex = {};
        // position
        vertex.m_position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        // uv
        if (mesh->mTextureCoords[0]) {
            vertex.m_texCoord.x = (float)mesh->mTextureCoords[0][i].x;
            vertex.m_texCoord.y = (float)mesh->mTextureCoords[0][i].y;
        }

        vertices.push_back(vertex);
    }

    // normal
    if (mesh->mNormals != nullptr) {
        for (GLuint i = 0; i < mesh->mNumVertices; i++) {
            Vertex& vertex = vertices[i];
            aiVector3D normal = mesh->mNormals[i];
            vertex.m_normal = glm::vec3(normal.x, normal.y, normal.z);
        }
    }

    // indices
    for (GLuint i = 0; i < mesh->mNumFaces; i++) {
        aiFace face = mesh->mFaces[i];

        for (GLuint j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    // TODO... 处理材质和纹理
    if (mesh->mMaterialIndex >= 0) {
//        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
//
//        // 处理不同类型的纹理，比如漫反射、高光、法线贴图等。
//        std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse", scene);
//
//        std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular", scene);
//
//        _textures.insert(_textures.end(), diffuseMaps.begin(), diffuseMaps.end());
//        _textures.insert(_textures.end(), specularMaps.begin(), specularMaps.end());
    }
    return std::make_shared<Mesh>(vertices, indices);
}

std::vector<Texture> AssimpModelLoader::loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName,
                                                             const aiScene *scene) {
    return std::vector<Texture>();
}

void AssimpModelLoader::loadEmbeddedTexture(const aiTexture *embeddedTexture, Texture &texture) {

}
