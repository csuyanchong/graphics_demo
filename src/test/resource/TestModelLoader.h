/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-23
 * File: TestModelLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_RESOURCE_TESTMODELLOADER_H_
#define GRAPHICS_DEMO_SRC_TEST_RESOURCE_TESTMODELLOADER_H_


#include "../TestEnvironment.h"
#include "../../graphics/Shader.h"
#include "../../graphics/Model.h"
#include "../../graphics/Camera.h"

class TestModelLoader : public TestEnvironment {
public:
    ~TestModelLoader() override;

protected:
    void init() override;

    void render() override;

private:
    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Model> m_model;
    std::shared_ptr<Material> m_material;
    std::shared_ptr<Texture> m_texture;
    std::shared_ptr<Camera> m_camera;
};


#endif //GRAPHICS_DEMO_SRC_TEST_RESOURCE_TESTMODELLOADER_H_
