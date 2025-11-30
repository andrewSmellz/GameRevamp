cmake_minimum_required(VERSION 3.10)

project(GameRevamp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------
# FetchContent setup
# -------------------------------------------------------
include(FetchContent)

# -------------------------------------------------------
# Fetch GLFW
# -------------------------------------------------------
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG latest
)

# Make GLFW available
FetchContent_MakeAvailable(glfw)

# -------------------------------------------------------
# GLAD (local)
# -------------------------------------------------------
add_library(glad external/GLAD/src/glad.c)
target_include_directories(glad PUBLIC external/GLAD/include)

# -------------------------------------------------------
# Executable
# -------------------------------------------------------
add_executable(GameRevamp
        src/main.cpp
)

# -------------------------------------------------------
# Linking
# -------------------------------------------------------
target_link_libraries(GameRevamp
        glad
        glfw
        opengl32
)

# If you want include/ folder available everywhere:
target_include_directories(GameRevamp PRIVATE include)
