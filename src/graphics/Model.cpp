/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-9
 * File: Model
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "Model.h"

void Model::addMesh(const std::shared_ptr<Mesh> &mesh) {
    m_meshes.push_back(mesh);
}

void Model::addMatrial(const std::shared_ptr<Material> &material) {
    m_materials.push_back(material);
}

void Model::render() const{
    for (const auto& mesh : m_meshes) {
        mesh->draw();
    }
}

Model::~Model() {
    m_meshes.clear();
    m_materials.clear();
}
