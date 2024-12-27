/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-9
 * File: Model
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_GRAPHICS_MODEL_H_
#define GRAPHICS_DEMO_SRC_GRAPHICS_MODEL_H_


#include <vector>
#include <memory>

#include "Mesh.h"
#include "material/Material.h"

class Model {
public:
    Model() = default;
    ~Model();

    void addMesh(const std::shared_ptr<Mesh>& mesh);
    void addMaterial(const std::shared_ptr<Material>& material);
    void render() const;

public:
    std::string m_name;
    std::string m_directory;

private:
    std::vector<std::shared_ptr<Mesh>> m_meshes;
    std::vector<std::shared_ptr<Material>> m_materials;
};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_MODEL_H_
