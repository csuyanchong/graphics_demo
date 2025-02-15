/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: ResourceManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <iostream>
#include "../graphics/GeometryFactory.h"

#include "ResourceManager.h"


std::shared_ptr<Model>
ResourceManager::loadModel(const std::string &filePath, ResourceLoaderFactory::ModelLoaderType loaderType) {
    if (m_models.find(filePath) != m_models.end()) {
        return m_models[filePath];
    }

    auto loader = ResourceLoaderFactory::createModelLoader(loaderType);
    auto model = loader->loadModel(filePath);
    m_models[filePath] = model;
    return model;
}

std::shared_ptr<Shader> ResourceManager::loadShader(const std::string &vertPath, const std::string &fragPath) {
    // 缓存处理
    std::string key = vertPath + fragPath;
    if (m_shaderCache.find(key) != m_shaderCache.end()) {
        return m_shaderCache[key];
    }
    auto shader = std::make_shared<Shader>(vertPath, fragPath);
    m_shaderCache[key] = shader;
    return shader;
}

std::shared_ptr<Texture>
ResourceManager::loadTexture(const std::string &path, ResourceLoaderFactory::TextureLoaderType loaderType) {
    if (m_textures.find(path) != m_textures.end()) {
        return m_textures[path];
    }

    auto loader = ResourceLoaderFactory::createTextureLoader(loaderType);
    auto texture = loader->loadTexture(path);
    m_textures[path] = texture;
    return texture;
}

void ResourceManager::registerResourcePath(const std::string &type, const std::string &path) {
    m_paths[type] = m_assetRoot + path;
}

std::string ResourceManager::getResourcePath(const std::string &type, const std::string &name) const {
    if (m_paths.find(type) != m_paths.end()) {
        return m_paths.at(type) + name;
    }
    throw std::runtime_error("Resource type not registered: " + type);
}

std::shared_ptr<Mesh> ResourceManager::getPlaneMesh(float width, float height) {
    std::string key = std::string("plane") + "_" + std::to_string(width) + "_" + std::to_string(height);
    if (m_meshes.find(key) != m_meshes.end()) {
        return m_meshes[key];
    }
    // 生成一个plane mesh
    std::shared_ptr<Mesh> res = GeometryFactory::createPlaneMesh(width, height);
    return res;
}

void ResourceManager::unload() {
    m_models.clear();
    m_meshes.clear();
    m_textures.clear();
    m_shaderCache.clear();
    m_paths.clear();
}

