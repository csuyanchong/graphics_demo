/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Scene
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_SCENE_SCENE_H_
#define GRAPHICS_DEMO_SRC_SCENE_SCENE_H_


#include "GameObject.h"

class Scene {
public:
    Scene();
    ~Scene() = default;

    void addGameObject(std::shared_ptr<GameObject>& gameObject);

    void update(float deltaTime);

    void render();

    std::shared_ptr<GameObject>& getRoot();

private:
    std::shared_ptr<GameObject> m_root;
};


#endif //GRAPHICS_DEMO_SRC_SCENE_SCENE_H_
