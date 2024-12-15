/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-15
 * File: StbImageTextureLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_LOADER_STBIMAGETEXTURELOADER_H_
#define GRAPHICS_DEMO_SRC_CORE_LOADER_STBIMAGETEXTURELOADER_H_


#include "ITextureLoader.h"

class StbImageTextureLoader : public ITextureLoader{
public:
    std::shared_ptr<Texture> loadTexture(const std::string &path) override {
        // TODO... 使用stb加载image
        std::vector<unsigned char> data;
        int width = 1024;
        int height = 1024;
        int chanel = 4;
        auto res = std::make_shared<Texture>(data, width, height, chanel);
        return res;
    }
};


#endif //GRAPHICS_DEMO_SRC_CORE_LOADER_STBIMAGETEXTURELOADER_H_
