#include "engine/Window.h"
#include "engine/Renderer.h"
#include "engine/MeshFactory.h"
#include "engine/Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/Colours.h>


constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
const std::string WINDOW_TITLE = "Awesome Game Window";

int main() {
    const Window window(WIDTH, HEIGHT, WINDOW_TITLE);
    const Shader shader("../assets/shaders/shader.vert", "../assets/shaders/shader.frag");
    const Renderer renderer;

    auto triangle = MeshFactory::generateTriangle();
    auto rectangle = MeshFactory::generateRectangle();

    auto texturedCircle = MeshFactory::generateTexturedCircle(128);
    auto texturedRectangle = MeshFactory::generateTexturedRectangle();


    Texture texture1("../assets/textures/voices.png");
    Texture texture2("../assets/textures/leak1.png");

    triangle->setColor(Colours::CYAN);
    rectangle->setColor(Colours::ORANGE);
    texturedCircle->setColor(Colours::RED);
    texturedRectangle->setColor(Colours::BROWN);

    constexpr auto identity = glm::mat4(1.0f);
    constexpr auto transform1 = glm::translate(identity, glm::vec3(0.5f, 0.5f, 0.0f));
    constexpr auto transform2 = glm::translate(identity, glm::vec3(-0.5f, -0.5f, 0.0f));
    constexpr auto transform3 = glm::translate(identity, glm::vec3(0.5f, -0.5f, 0.0f));
    constexpr auto transform4 = glm::translate(identity, glm::vec3(-0.5f, 0.5f, 0.0f));

    while (!window.shouldClose()) {
        window.processInput();
        Renderer::clear();
        renderer.draw(*triangle, shader, transform1);
        renderer.draw(*rectangle, shader, transform2);
        renderer.draw(*texturedCircle, shader, transform3, &texture2);
        renderer.draw(*texturedRectangle, shader, transform4, &texture1);
        window.swapBuffers();
        window.pollEvents();
    }
    return 0;
}

