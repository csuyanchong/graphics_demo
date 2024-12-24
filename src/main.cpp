#include "app/Application.h"
#include "test/TestRegistry.h"
#include "test/TestManager.h"

void runTests() {
    TestRegistry::instance();
    TestManager::getInstance().runAllTest();
}

int main() {
    // 运行测试
    runTests();

    // 启动应用
    Application app;
    app.run();
    return 0;
}