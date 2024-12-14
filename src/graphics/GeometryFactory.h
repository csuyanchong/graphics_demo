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
    static std::shared_ptr<Mesh> createPlaneMesh(float width, float height) {
        std::shared_ptr<Mesh> res;
        // 定义四边形4个顶点，顺序为：左下角-右下角-右上角-左上角。
        Vertex vert0 = Vertex{glm::vec3(-width / 2, -height / 2, 0),
                              glm::vec3(0, 0, 1),
                              glm::vec2(0, 0)
        };
        Vertex vert1 = Vertex{glm::vec3(width / 2, -height / 2, 0),
                              glm::vec3(0, 0, 1),
                              glm::vec2(1, 0)
        };
        Vertex vert2 = Vertex{glm::vec3(width / 2, height / 2, 0),
                              glm::vec3(0, 0, 1),
                              glm::vec2(1, 1)
        };
        Vertex vert3 = Vertex{glm::vec3(-width / 2, height / 2, 0),
                              glm::vec3(0, 0, 1),
                              glm::vec2(0, 1)
        };

        std::vector<Vertex> vertices{vert0, vert1, vert2, vert3};
        std::vector<GLuint> indices{0, 1, 2,
                                    0, 2, 3
        };

        res = std::make_shared<Mesh>(vertices, indices);
        return res;
    };
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_GEOMETRYFACTORY_H_
