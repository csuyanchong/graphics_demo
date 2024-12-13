/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: ResourceManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_RESOURCEMANAGER_H_
#define GRAPHICS_DEMO_SRC_CORE_RESOURCEMANAGER_H_

#include <memory>
#include <string>

#include "../graphics/Model.h"
#include "../graphics/Shader.h"
#include "../graphics/Texture.h"

class ResourceManager {
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    void registerResourcePath(const std::string& type, const std::string& path);
    std::string getResourcePath(const std::string& type, const std::string& name) const;

    std::shared_ptr<Model> loadModel(const std::string& path);
    std::shared_ptr<Shader> loadShader(const std::string& vertPath, const std::string& fragPath);
    std::shared_ptr<Texture> loadTexture(const std::string& path);

public:
    ResourceManager(ResourceManager const&) = delete;
    void operator=(ResourceManager const&) = delete;

private:
    ResourceManager() = default;
    ~ResourceManager() = default;

private:
    std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaderCache;
    std::string m_assetRoot = "../../assets/";
    std::unordered_map<std::string, std::string> m_paths;
};


#endif //GRAPHICS_DEMO_SRC_CORE_RESOURCEMANAGER_H_
