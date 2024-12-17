/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-16
 * File: AssimpModelLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_LOADER_ASSIMPMODELLOADER_H_
#define GRAPHICS_DEMO_SRC_CORE_LOADER_ASSIMPMODELLOADER_H_


#include "IModelLoader.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class AssimpModelLoader : public IModelLoader{
public:
    std::shared_ptr<Model> loadModel(const std::string &path) override;

private:
    void processNode(aiNode* node, const aiScene* scene, std::shared_ptr<Model>& model);
    std::shared_ptr<Mesh> processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName, const
    aiScene* scene);
    void loadEmbeddedTexture(const aiTexture* embeddedTexture, Texture& texture);
};


#endif //GRAPHICS_DEMO_SRC_CORE_LOADER_ASSIMPMODELLOADER_H_
