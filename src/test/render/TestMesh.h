/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-23
 * File: TestMesh
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_RENDER_TESTMESH_H_
#define GRAPHICS_DEMO_SRC_TEST_RENDER_TESTMESH_H_


#include "../TestEnvironment.h"
#include "../../graphics/Shader.h"
#include "../../graphics/Mesh.h"

class TestMesh : public TestEnvironment {
public:
    ~TestMesh() override;

protected:
    void init() override;

    void render() override;

private:
    std::shared_ptr<Mesh> createMesh();

    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Mesh> m_mesh;

};


#endif //GRAPHICS_DEMO_SRC_TEST_RENDER_TESTMESH_H_
