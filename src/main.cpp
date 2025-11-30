#include "engine/Window.h"
#include "engine/Renderer.h"
#include <iostream>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
const std::string WINDOW_TITLE = "Awesome Game Window";

int main() {
    Window window(WIDTH, HEIGHT, WINDOW_TITLE);
    Shader shader("../assets/shaders/shader.vert", "../assets/shaders/shader.frag");
    Renderer renderer{};
    while (!window.shouldClose()) {
        window.processInput();
        renderer.clear();
        renderer.drawTestTriangle(shader);
        window.swapBuffers();
        window.pollEvents();
    }
    return 0;
}

