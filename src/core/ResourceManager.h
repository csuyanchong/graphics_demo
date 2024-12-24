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
#include "../graphics/Mesh.h"
#include "factory/ResourceLoaderFactory.h"

class ResourceManager {
public:
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    void registerResourcePath(const std::string& type, const std::string& path);
    std::string getResourcePath(const std::string& type, const std::string& name) const;

    std::shared_ptr<Model> loadModel(const std::string &path, ResourceLoaderFactory::ModelLoaderType loaderType);
    /**
     * @brief 加载shader。
     * @param vertPath 顶点着色器文件路径。
     * @param fragPath 片段着色器文件路径。
     * @return
     */
    std::shared_ptr<Shader> loadShader(const std::string& vertPath, const std::string& fragPath);

    /**
     * @brief 加载纹理图像。
     * @param path 图像地址。
     * @param loaderType 加载器类型。
     * @return
     */
    std::shared_ptr<Texture> loadTexture(const std::string &path, ResourceLoaderFactory::TextureLoaderType loaderType);

    /**
     * @brief 获取一个平面网格体。
     * @param width 平面宽度，默认为1。
     * @param height 平面高度，默认为1。
     * @return
     */
    std::shared_ptr<Mesh> getPlaneMesh(float width = 1.0f, float height = 1.0f);

    void unload();

public:
    ResourceManager(ResourceManager const&) = delete;
    void operator=(ResourceManager const&) = delete;

private:
    ResourceManager() = default;
    ~ResourceManager() = default;

private:
    std::string m_assetRoot = "../../assets/";

    std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaderCache;
    std::unordered_map<std::string, std::string> m_paths;
    std::unordered_map<std::string, std::shared_ptr<Mesh>> m_meshes;
    std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
    std::unordered_map<std::string, std::shared_ptr<Model>> m_models;
};


#endif //GRAPHICS_DEMO_SRC_CORE_RESOURCEMANAGER_H_
