//
// Created by andre on 2025-11-30.
//

#include "engine/Renderer.h"
#include <glad/glad.h>

Renderer::Renderer() : VAO(0), VBO(0) {
    testInitTriangle();
}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Renderer::testInitTriangle() {
    float vertices[] = {
        // positions        // colors
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // top (blue)
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left (red)
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f // bottom right (green)
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), reinterpret_cast<void *>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


void Renderer::drawTriangle(const Shader &shader, const glm::mat4 &mat) const {
    shader.use();
    shader.setMat4("model", mat);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}


void Renderer::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
