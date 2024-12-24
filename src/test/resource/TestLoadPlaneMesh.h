/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-24
 * File: TestLoadPlaneMesh
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_RESOURCE_TESTLOADPLANEMESH_H_
#define GRAPHICS_DEMO_SRC_TEST_RESOURCE_TESTLOADPLANEMESH_H_


#include "../TestEnvironment.h"
#include "../../graphics/Shader.h"
#include "../../graphics/Mesh.h"

class TestLoadPlaneMesh : public TestEnvironment {
public:
    ~TestLoadPlaneMesh() override;

protected:
    void init() override;

    void render() override;

private:
    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Mesh> m_mesh;
};


#endif //GRAPHICS_DEMO_SRC_TEST_RESOURCE_TESTLOADPLANEMESH_H_
