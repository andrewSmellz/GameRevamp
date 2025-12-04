cmake_minimum_required(VERSION 3.20)

project(GameRevamp VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ------------------------------------
# External directory for dependencies
# ------------------------------------
set(EXTERNAL_DIR "${CMAKE_SOURCE_DIR}/external")


# ------------------------------------
# Fetch GLFW
# ------------------------------------
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)

# ------------------------------------
# Fetch GLM
# ------------------------------------
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
)

# Download dependencies
FetchContent_MakeAvailable(glfw glm)

# ------------------------------------
# Download just stb_image.h
# ------------------------------------
set(STB_IMAGE_URL "https://raw.githubusercontent.com/nothings/stb/master/stb_image.h")
set(STB_IMAGE_PATH "${EXTERNAL_DIR}/stb/stb_image.h")

if (NOT EXISTS ${STB_IMAGE_PATH})
    message(STATUS "Downloading stb_image.h...")
    file(DOWNLOAD ${STB_IMAGE_URL} ${STB_IMAGE_PATH}
            SHOW_PROGRESS
            STATUS DOWNLOAD_STATUS)
    list(GET DOWNLOAD_STATUS 0 STATUS_CODE)
    if (NOT STATUS_CODE EQUAL 0)
        message(FATAL_ERROR "Failed to download stb_image.h")
    endif ()
    message(STATUS "stb_image.h downloaded successfully")
endif ()


# ------------------------------------
# GLAD library
# ------------------------------------
add_library(glad external/GLAD/src/glad.c)
target_include_directories(glad PUBLIC external/GLAD/include)


# ------------------------------------
# GameRevamp executable
# ------------------------------------
add_executable(GameRevamp
        src/main.cpp
        src/engine/Window.cpp
        include/engine/Window.h
        src/engine/Shader.cpp
        include/engine/Shader.h
        src/engine/Renderer.cpp
        include/engine/Renderer.h
        src/engine/Mesh.cpp
        include/engine/Mesh.h
        src/engine/MeshFactory.cpp
        include/engine/MeshFactory.h
        include/engine/Colours.h
        src/engine/Texture.cpp
        include/engine/Texture.h
)


# ------------------------------------
# Linking
# ------------------------------------
target_link_libraries(GameRevamp
        glad
        glfw
        glm::glm
        opengl32
)


# ------------------------------------
# Include directories
# ------------------------------------
target_include_directories(GameRevamp PRIVATE
        include
        ${EXTERNAL_DIR}/stb   # stb_image.h lives here
)