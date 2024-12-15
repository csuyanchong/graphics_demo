/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-15
 * File: ITextureLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_LOADER_ITEXTURELOADER_H_
#define GRAPHICS_DEMO_SRC_CORE_LOADER_ITEXTURELOADER_H_


#include <memory>
#include <string>
#include "../../graphics/Texture.h"

/**
 * @brief 纹理加载器接口。
 */
class ITextureLoader {
public:
    virtual std::shared_ptr<Texture> loadTexture(const std::string& path) = 0;
    virtual ~ITextureLoader() = default;
};


#endif //GRAPHICS_DEMO_SRC_CORE_LOADER_ITEXTURELOADER_H_
