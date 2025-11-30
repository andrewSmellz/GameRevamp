cmake_minimum_required(VERSION 3.10)

project(GameRevamp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)


FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG latest
)


FetchContent_MakeAvailable(glfw)


add_library(glad external/GLAD/src/glad.c)
target_include_directories(glad PUBLIC external/GLAD/include)


add_executable(GameRevamp
        src/main.cpp
        src/engine/Window.cpp
        include/engine/Window.h
        src/engine/Shader.cpp
        include/engine/Shader.h
        src/engine/Renderer.cpp
        include/engine/Renderer.h
)


target_link_libraries(GameRevamp
        glad
        glfw
        opengl32
)

target_include_directories(GameRevamp PRIVATE include)
