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
        src/graphics/Texture.cpp
        src/graphics/Texture.h
        src/graphics/Shader.cpp
        src/graphics/Shader.h
        src/core/test/TestOpenGlRendering.h
        src/graphics/Mesh.cpp
        src/graphics/Mesh.h
        src/graphics/Light.cpp
        src/graphics/Light.h
        src/core/ResourceManager.cpp
        src/core/ResourceManager.h
        src/core/Component.cpp
        src/core/Component.h
        src/graphics/MeshRenderer.cpp
        src/graphics/MeshRenderer.h
        src/graphics/Material.cpp
        src/graphics/Material.h
        src/graphics/PbrMaterial.cpp
        src/graphics/PbrMaterial.h
        src/core/Scene.cpp
        src/core/Scene.h
        src/core/GameObject.cpp
        src/core/GameObject.h
        src/core/Transform.cpp
        src/core/Transform.h
        src/graphics/Model.cpp
        src/graphics/Model.h
        src/test/TestBasicRendering.h
        src/test/TestMesh.h
        src/graphics/GeometryFactory.h
        src/test/TestLoadPlaneMesh.h
)

# 生成可执行文件
add_executable(graphics_demo ${SOURCES})

# 链接库
target_link_libraries(graphics_demo PRIVATE
        glfw
        glm::glm
        unofficial::gl3w::gl3w
)
