/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: GameObject
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_GAMEOBJECT_H_
#define GRAPHICS_DEMO_SRC_CORE_GAMEOBJECT_H_


#include <memory>

#include "Transform.h"
#include "../graphics/Mesh.h"

class GameObject {
public:
    Transform m_transform;
    std::shared_ptr<Mesh> m_mesh;

};


#endif //GRAPHICS_DEMO_SRC_CORE_GAMEOBJECT_H_
