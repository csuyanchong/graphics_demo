/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: ResourceManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <iostream>
#include "ResourceManager.h"

std::shared_ptr<Model> ResourceManager::loadModel(const std::string &filePath) {
    auto model = std::make_shared<Model>();
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

std::shared_ptr<Texture> ResourceManager::loadTexture(const std::string &path) {
    return std::shared_ptr<Texture>();
}

void ResourceManager::registerResourcePath(const std::string &type, const std::string &path) {
    m_paths[type] = m_assetRoot + path;
}

std::string ResourceManager::getResourcePath(const std::string &type, const std::string &name) const{
    if (m_paths.find(type) != m_paths.end()) {
        return m_paths.at(type) + name;
    }
    throw std::runtime_error("Resource type not registered: " + type);
}
