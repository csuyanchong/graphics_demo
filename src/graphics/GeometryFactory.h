/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-14
 * File: GeometryFactory
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_GEOMETRYFACTORY_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_GEOMETRYFACTORY_H_

#include <memory>
#include <vector>

#include "Mesh.h"

/**
 * @brief 基本体网格工厂。
 */
class GeometryFactory {
public:
    /**
     * @brief 创建平面网格。
     * @param width 平面宽度。
     * @param height 平面高度。
     * @return
     */
    static std::shared_ptr<Mesh> createPlaneMesh(float width, float height);

    static std::shared_ptr<Mesh> createCubeMesh(float size = 1.0f);
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_GEOMETRYFACTORY_H_
