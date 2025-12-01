
#include "engine/Mesh.h"
#include <glad/glad.h>

// Constructor for no EBO or indexing
Mesh::Mesh(const std::vector<float> &vertices, int stride)
    : VAO(0), VBO(0), EBO(0), vertexCount(0), stride(stride), useIndices(false), indexCount(0) {
    vertexCount = vertices.size() / stride;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), static_cast<void *>(0));
    glEnableVertexAttribArray(0);

    if (stride > 3) {
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float),
                              reinterpret_cast<void *>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

// Constructor with EBO for indexed drawing
Mesh::Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, int stride)
    : VAO(0), VBO(0), EBO(0), vertexCount(0), stride(stride), useIndices(true), indexCount(0) {
    vertexCount = vertices.size() / stride;
    indexCount = indices.size();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float), static_cast<void *>(0));
    glEnableVertexAttribArray(0);

    if (stride > 3) {
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride * sizeof(float),
                              reinterpret_cast<void *>(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Mesh::bind() const {
    glBindVertexArray(VAO);
}

void Mesh::unbind() const {
    glBindVertexArray(0);
}

int Mesh::getVertexCount() const {
    return vertexCount;
}

void Mesh::draw() const {
    bind();
    if (useIndices) {
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
    }
}





