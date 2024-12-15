/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-15
 * File: TestTexture
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_TESTTEXTURE_H_
#define GRAPHICS_DEMO_SRC_TEST_TESTTEXTURE_H_

#include <iostream>

#include <GL/gl3w.h>
#include <memory>

#include "../core/factory/ResourceLoaderFactory.h"
#include "../graphics/Shader.h"
#include "../core/ResourceManager.h"

class TestTexture {
public:
    void init() {
        // 注册资源路径
        ResourceManager::getInstance().registerResourcePath("shaders", "shaders/");
        ResourceManager::getInstance().registerResourcePath("textures", "textures/");
        // shader文件地址
        std::string vertPath = ResourceManager::getInstance().getResourcePath("shaders","texture.vert");
        std::string fragPath = ResourceManager::getInstance().getResourcePath("shaders","texture.frag");
        // 初始化简单的着色器
        m_shader = ResourceManager::getInstance().loadShader(vertPath, fragPath);

        // 创建mesh
        m_mesh = ResourceManager::getInstance().getPlaneMesh();

        // 纹理地址
        std::string texturePath = ResourceManager::getInstance().getResourcePath("textures","brick.png");
        // 创建纹理
        m_texture = ResourceManager::getInstance().loadTexture(texturePath, ResourceLoaderFactory::TextureLoaderType::LODEPNG);
    }

    void render() {
        // 启用shader
        m_shader->bind();

        // 启用纹理
        m_texture->bind(m_textureUnit);

        // 设置shader参数
        m_shader->setUniform("texture_sample", m_textureUnit);

        // 绘制
        m_mesh->draw();

        m_texture->unBind();
        m_shader->unBind();
    }

private:
    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Mesh> m_mesh;
    std::shared_ptr<Texture> m_texture;

    GLint m_textureUnit = 1;
    std::shared_ptr<Texture> createCheckBoardTexture() {
        std::vector<unsigned char> data {255, 0, 0,
                                         255, 255, 0,
                                         255, 0, 0,
                                         255, 255, 0};
        int width = 400;
        int height = 400;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                data.push_back(i % 255);
                data.push_back(j % 255);
                data.push_back(j % 255);
            }
        }
        std::shared_ptr<Texture> res = std::make_shared<Texture>(data, width, height, 3);
        return res;
    };
};


#endif //GRAPHICS_DEMO_SRC_TEST_TESTTEXTURE_H_
