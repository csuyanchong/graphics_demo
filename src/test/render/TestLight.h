/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-26
 * File: TestLight
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_RENDER_TESTLIGHT_H_
#define GRAPHICS_DEMO_SRC_TEST_RENDER_TESTLIGHT_H_

#include "../TestEnvironment.h"
#include "../../graphics/camera/Camera.h"
#include "../../graphics/camera/CameraController.h"
#include "../../graphics/light/Light.h"
#include "../../graphics/material/BlinnPhongMaterial.h"

class TestLight : public TestEnvironment {
public:
    ~TestLight() override;

    void run() override;

protected:
    void init() override;

    void render() override;

    double m_currentTime{.0};
    double m_lastTime{.0};
    float m_fps{.0f};

private:
    float getDeltaTime();

    void processInput(float deltaTime);

    void update(float deltaTime);

    void preCompute();

    std::shared_ptr<Shader> m_shader;
    std::shared_ptr<Model> m_model;
    std::shared_ptr<BlinnPhongMaterial> m_material;
    std::shared_ptr<Texture> m_texture;
    std::shared_ptr<Camera> m_camera;
    std::shared_ptr<CameraController> m_cameraController;
    std::shared_ptr<DirectionalLight> m_directionalLight;

    // ambient color
    glm::vec3 m_materialKa{1.0f, 0, 0};
    // diffuse color
    glm::vec3 m_materialKd{1.0f, 0, 0};
    // specular color
    glm::vec3 m_materialKs{1.0f, 1.0f, 1.0f};
    // shininess
    float m_materialAlpha{64.f};
};


#endif //GRAPHICS_DEMO_SRC_TEST_RENDER_TESTLIGHT_H_
