/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestShader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_RENDER_TESTSHADER_H_
#define GRAPHICS_DEMO_SRC_TEST_RENDER_TESTSHADER_H_


#include "../TestEnvironment.h"
#include "../../graphics/Shader.h"

class TestShader : public TestEnvironment {
public:
    ~TestShader() override;

protected:
    void init() override;

    void render() override;

private:
    GLuint m_vao{}, m_vbo{};
    std::shared_ptr<Shader> m_shader;
};

#endif //GRAPHICS_DEMO_SRC_TEST_RENDER_TESTSHADER_H_
