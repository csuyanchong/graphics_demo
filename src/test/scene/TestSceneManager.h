/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-28
 * File: TestSceneManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_SCENE_TESTSCENEMANAGER_H_
#define GRAPHICS_DEMO_SRC_TEST_SCENE_TESTSCENEMANAGER_H_


#include "../TestEnvironment.h"

class TestSceneManager : public TestEnvironment {
public:
    ~TestSceneManager() override;

    void run() override;

protected:
    void init() override;

    void render() override;
};


#endif //GRAPHICS_DEMO_SRC_TEST_SCENE_TESTSCENEMANAGER_H_
