#include "engine/Window.h"
#include "engine/Renderer.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
const std::string WINDOW_TITLE = "Awesome Game Window";

int main() {
    const Window window(WIDTH, HEIGHT, WINDOW_TITLE);
    const Shader shader("../assets/shaders/shader.vert", "../assets/shaders/shader.frag");
    const Renderer renderer{};

    constexpr auto identity = glm::mat4(1.0f);

    constexpr auto transform1 = glm::mat4(1.0f);
    constexpr auto transform2 = glm::translate(identity, glm::vec3(0.5f, 0.5f, 0.0f));
    constexpr auto transform3 = glm::translate(identity, glm::vec3(-0.5f, -0.5f, 0.0f));

    while (!window.shouldClose()) {
        window.processInput();
        Renderer::clear();
        renderer.drawTriangle(shader, transform1);
        renderer.drawTriangle(shader, transform2);
        renderer.drawTriangle(shader, transform3);
        window.swapBuffers();
        window.pollEvents();
    }
    return 0;
}

