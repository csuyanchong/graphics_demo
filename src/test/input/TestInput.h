/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-25
 * File: TestInput
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_INPUT_TESTINPUT_H_
#define GRAPHICS_DEMO_SRC_TEST_INPUT_TESTINPUT_H_


#include "../../graphics/Shader.h"
#include "../../graphics/Model.h"
#include "../../graphics/camera/Camera.h"
#include "../../graphics/camera/CameraController.h"

#include "../TestEnvironment.h"

class TestInput : public TestEnvironment{
public:
    ~TestInput() override;

    void run() override;

protected:
    void init() override;

    void render() override;

    double m_currentTime = 0;
    double m_lastTime = 0;
    float m_fps = 0;
private:
    float getDeltaTime();
    void processInput(float deltaTime);
    void update(float deltaTime);

    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Model> m_model;
    std::shared_ptr<Material> m_material;
    std::shared_ptr<Texture> m_texture;
    std::shared_ptr<Camera> m_camera;
    std::shared_ptr<CameraController> m_cameraController;
};


#endif //GRAPHICS_DEMO_SRC_TEST_INPUT_TESTINPUT_H_
