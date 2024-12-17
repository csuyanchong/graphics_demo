/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-16
 * File: ResourceLoaderFactory
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "ResourceLoaderFactory.h"
#include "../loader/LodepngTextureLoader.h"
#include "../loader/StbImageTextureLoader.h"
#include "../loader/AssimpModelLoader.h"

std::shared_ptr<ITextureLoader> ResourceLoaderFactory::createTextureLoader(ResourceLoaderFactory::TextureLoaderType type) {
    switch (type) {
        case TextureLoaderType::LODEPNG:
            return std::make_shared<LodepngTextureLoader>();
        case TextureLoaderType::STB_IMG:
            return std::make_shared<StbImageTextureLoader>();
        default:
            throw std::invalid_argument("Unsupported texture loader type");
    }
}

std::shared_ptr<IModelLoader> ResourceLoaderFactory::createModelLoader(ResourceLoaderFactory::ModelLoaderType type) {
    switch (type) {
        case ModelLoaderType::ASSIMP:
            return std::make_shared<AssimpModelLoader>();
        default:
            throw std::invalid_argument("Unsupported model loader type");
    }
}
