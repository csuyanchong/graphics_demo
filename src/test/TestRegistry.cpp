/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestRegistry
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include "TestManager.h"
#include "render/TestShader.h"
#include "render/TestMesh.h"
#include "render/TestTexture.h"
#include "resource/TestModelLoader.h"
#include "resource/TestLoadPlaneMesh.h"
#include "input/TestInput.h"
#include "render/TestLight.h"

#include "TestRegistry.h"

TestRegistry::TestRegistry() {
    TestManager &testManager = TestManager::getInstance();
    std::unique_ptr<TestEnvironment> testScene;

    // shader加载
    testScene = std::make_unique<TestShader>();
    testManager.registerTestScene(testScene);

    // mesh加载
    testScene = std::make_unique<TestMesh>();
    testManager.registerTestScene(testScene);

    // 加载自定义四边形网格
    testScene = std::make_unique<TestLoadPlaneMesh>();
    testManager.registerTestScene(testScene);

    // texture加载
    testScene = std::make_unique<TestTexture>();
    testManager.registerTestScene(testScene);

    // model加载
    testScene = std::make_unique<TestModelLoader>();
    testManager.registerTestScene(testScene);

    // 输入和相机控制
    testScene = std::make_unique<TestInput>();
    testManager.registerTestScene(testScene);

    // 灯光测试
    testScene = std::make_unique<TestLight>();
    testManager.registerTestScene(testScene);
}
