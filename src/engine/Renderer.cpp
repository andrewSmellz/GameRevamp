
#include "engine/Renderer.h"
#include <glad/glad.h>

Renderer::Renderer() {
}

Renderer::~Renderer() {
}

void Renderer::draw(const Mesh &mesh, const Shader &shader, const glm::mat4 &transform) const {
    shader.use();
    shader.setMat4("model", transform);
    mesh.draw();
}


void Renderer::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
