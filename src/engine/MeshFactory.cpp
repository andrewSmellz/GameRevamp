

#include "../../include/engine/MeshFactory.h"

#include <cmath>

std::unique_ptr<Mesh> MeshFactory::generateTriangle() {
    std::vector<float> vertices = {
        0.0f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };
    return std::make_unique<Mesh>(vertices, 3);
}

std::unique_ptr<Mesh> MeshFactory::generateRectangle() {
    std::vector<float> vertices = {
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0
    };
    return std::make_unique<Mesh>(vertices, indices, 3);
}

std::unique_ptr<Mesh> MeshFactory::generateCircle(int segments) {
    std::vector<float> vertices;
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.1415926f * i / segments;
        float x = cosf(angle) * 0.5f;
        float y = sinf(angle) * 0.5f;
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f);
    }
    std::vector<unsigned int> indices;
    for (int i = 1; i <= segments; i++) {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }
    return std::make_unique<Mesh>(vertices, indices, 3);
}
