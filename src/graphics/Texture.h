/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: Texture
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_TEXTURE_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_TEXTURE_H_

#include <string>
#include <vector>
#include <gl/gl3w.h>

enum class TextureType {

};

class Texture {
public:
    Texture(std::vector<unsigned char>& data, int width, int height, int chanel);
    ~Texture();

    /**
     * @brief 绑定纹理到指定纹理单元。
     */
    void bind(unsigned int textureUnit) const;

    /**
     * @brief 取消绑定纹理。
     */
    void unBind() const;

private:
    GLuint m_idTexture = 0;
    std::vector<unsigned char> m_data;
    int m_width;
    int m_height;
    int m_chanel;
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_TEXTURE_H_
