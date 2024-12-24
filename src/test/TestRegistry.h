/*
 * Copyright (C) 2024 yanchong. All rights reserved.
 * Author: yanchong <yanchong0425@qq.com>
 * Created: 24-12-22
 * File: TestRegistry
 * Description: 
 * License: Licensed under the GPL-3.0 License. See LICENSE file in the project root for details.
 */

#ifndef GRAPHICS_DEMO_SRC_TEST_TESTREGISTRY_H_
#define GRAPHICS_DEMO_SRC_TEST_TESTREGISTRY_H_

/**
 * @brief 测试注册管理类。
 */
class TestRegistry {
public:
    static TestRegistry instance() {
        static TestRegistry instance;
        return instance;
    }

private:
    TestRegistry();
};


#endif //GRAPHICS_DEMO_SRC_TEST_TESTREGISTRY_H_
