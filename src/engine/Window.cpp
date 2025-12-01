
#include "engine/Window.h"
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


Window::Window(const int w, const int h, const std::string &title) : width(w), height(h), title(title) {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to open GLFW window." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallBack);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to load GLAD." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::framebufferSizeCallBack(GLFWwindow *window, const int width, const int height) {
    glViewport(0, 0, width, height);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

void Window::processInput() const {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void Window::swapBuffers() const {
    glfwSwapBuffers(window);
}

void Window::pollEvents() const {
    glfwPollEvents();
}

int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}

GLFWwindow *Window::getGlfwWindow() const {
    return window;
}









