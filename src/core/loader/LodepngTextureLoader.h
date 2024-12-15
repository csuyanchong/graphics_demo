/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-15
 * File: LodepngTextureLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_LOADER_LODEPNGTEXTURELOADER_H_
#define GRAPHICS_DEMO_SRC_CORE_LOADER_LODEPNGTEXTURELOADER_H_


#include <iostream>
#include "ITextureLoader.h"
#include "lodepng.h"

class LodepngTextureLoader : public ITextureLoader{
public:
    std::shared_ptr<Texture> loadTexture(const std::string &path) override {
        // 接收图像解码数据。
        std::vector<unsigned char> data;
        unsigned width = 0;
        unsigned height = 0;
        unsigned chanel = 4;

        // 使用lodepng库解码png图像。
        unsigned error = lodepng::decode(data, width, height, path);

        // 捕捉解码错误。
        if (error != 0) {
            std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
            // TODO... 日志系统捕捉报错信息。
            exit(EXIT_FAILURE);
        }

        // 翻转像素y轴数据，因为png图像坐标系和OpenGL texture坐标系原点不一致。
        flipPixelData(data, width, height, chanel);

        auto res = std::make_shared<Texture>(data, width, height, chanel);
        return res;
    }

private:
    /**
     * @brief 翻转图像像素数据。图像坐标系左上角变为左下角（或者左下角变为左上角）。
     * @param data 图像像素数据，字节数组。
     * @param width 图像宽度。
     * @param height 图像高度。
     * @param chanel 图像单个像素通道，RGBA为4，RGB为3。
     */
    void flipPixelData(std::vector<unsigned char> &data, unsigned width, unsigned height, unsigned chanel) {
        // 水平方向字节数
        unsigned widthBytes = width * chanel;

        for (unsigned i = 0; i < height / 2; ++i) {
            for (unsigned j = 0; j < widthBytes; ++j) {
                unsigned idUp = widthBytes * i + j;
                unsigned idDown = widthBytes * (height - i - 1) + j;
                std::swap(data[idUp], data[idDown]);
            }
        }
    }
};


#endif //GRAPHICS_DEMO_SRC_CORE_LOADER_LODEPNGTEXTURELOADER_H_
