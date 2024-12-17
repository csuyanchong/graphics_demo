/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-16
 * File: GeometryFactory
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <iostream>
#include "GeometryFactory.h"

std::shared_ptr<Mesh> GeometryFactory::createPlaneMesh(float width, float height) {
    std::shared_ptr<Mesh> res;
    // 定义四边形4个顶点，顺序为：左下角-右下角-右上角-左上角。
    auto vert0 = Vertex{glm::vec3(-width / 2, -height / 2, 0),
                          glm::vec3(0, 0, 1),
                          glm::vec2(0, 0)
    };
    auto vert1 = Vertex{glm::vec3(width / 2, -height / 2, 0),
                          glm::vec3(0, 0, 1),
                          glm::vec2(1, 0)
    };
    auto vert2 = Vertex{glm::vec3(width / 2, height / 2, 0),
                          glm::vec3(0, 0, 1),
                          glm::vec2(1, 1)
    };
    auto vert3 = Vertex{glm::vec3(-width / 2, height / 2, 0),
                          glm::vec3(0, 0, 1),
                          glm::vec2(0, 1)
    };

    std::vector<Vertex> vertices{vert0, vert1, vert2, vert3};
    std::vector<GLuint> indices{0, 1, 2,
                                0, 2, 3
    };

    res = std::make_shared<Mesh>(vertices, indices);
    return res;
}

std::shared_ptr<Mesh> GeometryFactory::createCubeMesh(float size) {
    std::shared_ptr<Mesh> res;
    // TODO... 创建立方体顶点信息
    std::cerr<< "Unimplemented function: create cube mesh. " << std::endl;
    std::vector<Vertex> vertices{};
    std::vector<GLuint> indices{};
    res = std::make_shared<Mesh>(vertices, indices);
    return res;
}


