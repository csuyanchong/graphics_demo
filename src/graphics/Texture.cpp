/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-7
 * File: Texture
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "Texture.h"

Texture::Texture(std::vector<unsigned char> &data, int width, int height, int chanel) : m_data(data),
                                                                                        m_width(width),
                                                                                        m_height(height),
                                                                                        m_chanel(chanel) {
    // 创建纹理缓存
    glGenTextures(1, &m_idTexture);
    glBindTexture(GL_TEXTURE_2D, m_idTexture);

    // 传输数据
    auto format = (chanel == 4) ? GL_RGBA : GL_RGB;

    glTexImage2D(
            GL_TEXTURE_2D,
            0,
            format,
            width,
            height,
            0,
            format,
            GL_UNSIGNED_BYTE,
            data.data()
    );

    // 参数设置
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::bind(unsigned int textureUnit) const {
    glActiveTexture((GLenum)(GL_TEXTURE0 + textureUnit));
    glBindTexture(GL_TEXTURE_2D, m_idTexture);
}

void Texture::unBind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_idTexture);
}
