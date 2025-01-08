/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: GameObject
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <stdexcept>
#include "../utils/LogUtil.h"

#include "GameObject.h"


void GameObject::addChild(std::shared_ptr<GameObject> &gameObject) {
    m_children.push_back(std::move(gameObject));
}

GameObject & GameObject::getChild(size_t index) {
    if (index >= m_children.size()) {
        LogUtil::error("Invalid index");
        throw std::out_of_range("Invalid index");
    }
    return *m_children[index];
}

std::weak_ptr<GameObject> GameObject::getParent() const {
    return m_parent;
}

GameObject::~GameObject() {
    m_children.clear();
    m_components.clear();
}

Transform &GameObject::getTransform() {
    return m_transform;
}

std::vector<std::shared_ptr<GameObject>> GameObject::getChildren() const {
    return m_children;
}

void GameObject::update(float deltaTime) {

}

void GameObject::render() {

}

template<typename T>
void GameObject::removeComponent() {
    auto res = getComponent<T>();
    if (res) {
        std::remove(m_components.begin(), m_components.end(), res);
    }
}

template<typename T>
std::shared_ptr<T> GameObject::getComponent() const {
    for (auto component : m_components) {
        if (auto res = std::dynamic_pointer_cast<T>(component)) {
            return res;
        }
    }
    return nullptr;
}

template<typename T, typename... Args>
std::shared_ptr<T> GameObject::addComponent(Args &&... args) {
    auto component = std::make_shared<T>(std::forward<Args>(args)...);
    m_components.push_back(component);
    return component;
}
