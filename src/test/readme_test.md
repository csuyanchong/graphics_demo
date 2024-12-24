# 测试模块说明
测试模块（Test Module），用于执行各类单元测试，确保不同模块的正确性。

## 组成
测试模块主要包括：TestManager、TestRegistry以及从TestEnvironment派生的测试场景。
1. TestManager
    测试管理器。注册、组织和执行测试，提供测试报告。
2. TestRegistry
    测试注册器。管理测试场景的注册。
3. TestEnvironment
    测试场景基类。封装了基本的窗口管理和帧更新函数。

## 测试入口
目前是main()函数内先调用测试注册，然后调用测试管理器中的runAllTest()方法，对注册过的所有场景逐个注册。

## 注意：
1. 测试场景需要public派生TestEnvironment类，并重写init()、render()、以及析构函数。

2. 测试场景需要在TestRegistry类中注册，注册后测试管理器才能测试，否则测试不会生效。

3. 测试场景需要在init()函数内修改窗口标题。

4. 测试场景需要在~destructor()中释放相关的资源，尤其是ResourceManager中的unload()函数。
