cmake_minimum_required(VERSION 3.30)
project(graphics_demo)

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找依赖库
find_package(gl3w CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(lodepng CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)

# 添加源文件
set(SOURCES src/main.cpp
        src/graphics/Texture.cpp
        src/graphics/Texture.h
        src/graphics/Shader.cpp
        src/graphics/Shader.h
        src/graphics/Mesh.cpp
        src/graphics/Mesh.h
        src/graphics/light/Light.cpp
        src/graphics/light/Light.h
        src/core/ResourceManager.cpp
        src/core/ResourceManager.h
        src/scene/Component.cpp
        src/scene/Component.h
        src/scene/MeshRenderer.cpp
        src/scene/MeshRenderer.h
        src/graphics/material/Material.cpp
        src/graphics/material/Material.h
        src/graphics/material/PbrMaterial.cpp
        src/graphics/material/PbrMaterial.h
        src/scene/Scene.cpp
        src/scene/Scene.h
        src/scene/GameObject.cpp
        src/scene/GameObject.h
        src/scene/Transform.cpp
        src/scene/Transform.h
        src/graphics/Model.cpp
        src/graphics/Model.h
        src/graphics/GeometryFactory.h
        src/core/loader/ITextureLoader.h
        src/core/loader/StbImageTextureLoader.h
        src/core/loader/LodepngTextureLoader.h
        src/core/factory/ResourceLoaderFactory.h
        src/core/loader/IModelLoader.h
        src/graphics/GeometryFactory.cpp
        src/graphics/material/BlinnPhongMaterial.cpp
        src/graphics/material/BlinnPhongMaterial.h
        src/core/loader/AssimpModelLoader.cpp
        src/core/loader/AssimpModelLoader.h
        src/core/factory/ResourceLoaderFactory.cpp
        src/graphics/camera/Camera.cpp
        src/graphics/camera/Camera.h
        src/app/Application.cpp
        src/app/Application.h
        src/test/TestManager.cpp
        src/test/TestManager.h
        src/test/TestEnvironment.cpp
        src/test/TestEnvironment.h
        src/test/TestRegistry.h
        src/test/TestRegistry.cpp
        src/test/render/TestShader.cpp
        src/test/render/TestShader.h
        src/test/resource/TestModelLoader.cpp
        src/test/resource/TestModelLoader.h
        src/test/render/TestMesh.cpp
        src/test/render/TestMesh.h
        src/test/render/TestTexture.cpp
        src/test/render/TestTexture.h
        src/utils/LogUtil.cpp
        src/utils/LogUtil.h
        src/test/resource/TestLoadPlaneMesh.cpp
        src/test/resource/TestLoadPlaneMesh.h
        src/graphics/camera/CameraController.cpp
        src/graphics/camera/CameraController.h
        src/input/InputManager.cpp
        src/input/InputManager.h
        src/test/input/TestInput.cpp
        src/test/input/TestInput.h
        src/test/render/TestLight.cpp
        src/test/render/TestLight.h
        src/test/scene/TestSceneManager.cpp
        src/test/scene/TestSceneManager.h
        src/scene/Rotation.cpp
        src/scene/Rotation.h
)

# 生成可执行文件
add_executable(graphics_demo ${SOURCES})

# 链接库
target_link_libraries(graphics_demo PRIVATE
        glfw
        glm::glm
        unofficial::gl3w::gl3w
        fmt::fmt
        lodepng
        assimp::assimp
)