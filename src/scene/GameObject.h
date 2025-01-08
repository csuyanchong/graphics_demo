/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-8
 * File: GameObject
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_SCENE_GAMEOBJECT_H_
#define GRAPHICS_DEMO_SRC_SCENE_GAMEOBJECT_H_


#include <memory>
#include <string>

#include "Component.h"
#include "Transform.h"

#include "../graphics/Mesh.h"

class GameObject : public std::enable_shared_from_this<GameObject> {
public:
    GameObject() : m_name("GameObject") {};

    explicit GameObject(const char *name) : m_name(name) {};

    explicit GameObject(std::string &name) : m_name(name) {};

    ~GameObject();

    Transform &getTransform();

    template<typename T, typename... Args>
    std::shared_ptr<T> addComponent(Args &&...args);

    template<typename T>
    std::shared_ptr<T> getComponent() const;

    template<typename T>
    void removeComponent();

    void addChild(std::shared_ptr<GameObject> &gameObject);

    GameObject &getChild(size_t index);

    size_t getChildCount() { return m_children.size(); }

    std::vector<std::shared_ptr<GameObject>> getChildren() const;

    std::weak_ptr<GameObject> getParent() const;

    std::string &getName() { return m_name; };

    void setName(std::string &name) { m_name = name; }

    void update(float deltaTime);

    void render();

private:
    Transform m_transform;
    std::vector<std::shared_ptr<Component>> m_components;
    std::vector<std::shared_ptr<GameObject>> m_children;
    std::weak_ptr<GameObject> m_parent;

    std::string m_name{};
};


#endif //GRAPHICS_DEMO_SRC_SCENE_GAMEOBJECT_H_
