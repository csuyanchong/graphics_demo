/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-15
 * File: ResourceLoaderFactory
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_FACTORY_RESOURCELOADERFACTORY_H_
#define GRAPHICS_DEMO_SRC_CORE_FACTORY_RESOURCELOADERFACTORY_H_


#include <memory>
#include "../loader/ITextureLoader.h"
#include "../loader/LodepngTextureLoader.h"
#include "../loader/StbImageTextureLoader.h"

class ResourceLoaderFactory {
public:
    enum class TextureLoaderType {
        LODEPNG,
        STB_IMG
    };

    static std::shared_ptr<ITextureLoader> createTextureLoader(TextureLoaderType type) {
        switch (type) {
            case TextureLoaderType::LODEPNG:
                return std::make_shared<LodepngTextureLoader>();
            case TextureLoaderType::STB_IMG:
                return std::make_shared<StbImageTextureLoader>();
            default:
                throw std::invalid_argument("Unsupported texture loader type");
        }
    };
};


#endif //GRAPHICS_DEMO_SRC_CORE_FACTORY_RESOURCELOADERFACTORY_H_
