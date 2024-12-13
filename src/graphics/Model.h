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


class Model {
public:
    Model() = default;
    ~Model() = default;

    void addMesh();
    void addMatrial();
    void draw();

private:

};


#endif //GRAPHICS_DEMO_SRC_GRAPHICS_MODEL_H_
