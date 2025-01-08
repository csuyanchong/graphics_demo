/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestManager
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#include <format>
#include "../utils/LogUtil.h"
#include "TestManager.h"

void TestManager::runAllTest() {
    LogUtil::info("Test start...");
    LogUtil::debug("test");
    LogUtil::error("test");
    LogUtil::warning("test");
    for (auto &testScene: m_testScenes) {
        try {
            runTest(testScene);
            // 打印测试通过
            std::string message = std::format("Test Success: {0}.", glfwGetWindowTitle(m_currentTest->getWindow()));
            LogUtil::info(message);
            m_currentTest = nullptr;
        } catch (std::exception &e) {
            // TODO...日志打印
            if (m_currentTest) {
                std::string message = std::format("Test failed: {0} ({1}).",
                                                  glfwGetWindowTitle(m_currentTest->getWindow()), e.what());
                LogUtil::info(message);
                m_currentTest = nullptr;
            }
            exit(EXIT_FAILURE);
        }
    }
    LogUtil::info("Test end.");
}

void TestManager::registerTestScene(std::unique_ptr<TestEnvironment> &testScene) {
    m_testScenes.emplace_back(std::move(testScene));
}

void TestManager::runTest(std::unique_ptr<TestEnvironment> &testScene) {
    m_currentTest = std::move(testScene);
    m_currentTest->initialize();
    m_currentTest->run();
}
