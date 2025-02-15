/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Component
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_SCENE_COMPONENT_H_
#define GRAPHICS_DEMO_SRC_SCENE_COMPONENT_H_


class Component {
public:
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

    virtual ~Component() = default;
};


#endif //GRAPHICS_DEMO_SRC_SCENE_COMPONENT_H_
