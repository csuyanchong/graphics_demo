cmake_minimum_required(VERSION 3.30)
project(graphics_demo)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找依赖库
find_package(gl3w CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# 添加源文件
set(SOURCES src/main.cpp
        src/core/test/TestBasicRendering.h
        src/graphics/Texture.cpp
        src/graphics/Texture.h
        src/graphics/Shader.cpp
        src/graphics/Shader.h
        src/core/test/TestOpenGlRendering.h
)

# 生成可执行文件
add_executable(graphics_demo ${SOURCES})

# 链接库
target_link_libraries(graphics_demo PRIVATE
        glfw
        glm::glm
        unofficial::gl3w::gl3w
)
