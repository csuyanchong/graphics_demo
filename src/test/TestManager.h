/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_TESTMANAGER_H_
#define GRAPHICS_DEMO_SRC_TEST_TESTMANAGER_H_


#include <functional>
#include <string>
#include <vector>
#include <utility>
#include <memory>

#include "TestEnvironment.h"

class TestManager {
public:
    static TestManager& getInstance() {
        static TestManager instance;
        return instance;
    }

    void registerTestScene(std::unique_ptr<TestEnvironment> &testScene);

    void runAllTest();

private:
    std::vector<std::unique_ptr<TestEnvironment>> m_testScenes;

    std::unique_ptr<TestEnvironment> m_currentTest;

    void runTest(std::unique_ptr<TestEnvironment> &testScene);

    TestManager() = default;
};


#endif //GRAPHICS_DEMO_SRC_TEST_TESTMANAGER_H_
