/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: Scene
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "Scene.h"

void Scene::addGameObject(std::shared_ptr<GameObject> &gameObject) {
    m_root->addChild(gameObject);
}

Scene::Scene() {
    m_root = std::make_unique<GameObject>("Root");
}

void Scene::update(float deltaTime) {
    for (const auto& object : m_root->getChildren()) {
        object->update(deltaTime);
    }
}

void Scene::render() {
    for (const auto& object : m_root->getChildren()) {
        object->render();
    }
}

std::shared_ptr<GameObject> &Scene::getRoot() {
    return m_root;
}
