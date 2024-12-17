/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-16
 * File: IModelLoader
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_CORE_LOADER_IMODELLOADER_H_
#define GRAPHICS_DEMO_SRC_CORE_LOADER_IMODELLOADER_H_


#include <memory>
#include <string>

#include "../../graphics/Model.h"

class IModelLoader {
public:
    virtual std::shared_ptr<Model> loadModel(const std::string& path) = 0;
    virtual ~IModelLoader() = default;
};


#endif //GRAPHICS_DEMO_SRC_CORE_LOADER_IMODELLOADER_H_
