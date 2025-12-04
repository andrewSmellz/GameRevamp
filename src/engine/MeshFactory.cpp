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

// ============================================
// TEXTURED VERSIONS
// ============================================

std::unique_ptr<Mesh> MeshFactory::generateTexturedTriangle() {
    // Positions (3) + Texture coords (2) = stride 5
    std::vector<float> vertices = {
        // positions        // texture coords
        0.0f, 0.5f, 0.0f, 0.5f, 1.0f, // top (center-top of texture)
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f // bottom right
    };
    auto mesh = std::make_unique<Mesh>(vertices, 5);
    mesh->setUseTexture(true);
    return mesh;
}

std::unique_ptr<Mesh> MeshFactory::generateTexturedRectangle() {
    // Positions (3) + Texture coords (2) = stride 5
    std::vector<float> vertices = {
        // positions        // texture coords
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, // top left
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f // bottom left
    };

    std::vector<unsigned int> indices = {
        0, 1, 2,
        2, 3, 0
    };

    auto mesh = std::make_unique<Mesh>(vertices, indices, 5);
    mesh->setUseTexture(true);
    return mesh;
}

std::unique_ptr<Mesh> MeshFactory::generateTexturedCircle(int segments) {
    // Positions (3) + Texture coords (2) = stride 5
    std::vector<float> vertices;

    // Center vertex (maps to center of texture)
    vertices.push_back(0.0f); // x
    vertices.push_back(0.0f); // y
    vertices.push_back(0.0f); // z
    vertices.push_back(0.5f); // tex u (center)
    vertices.push_back(0.5f); // tex v (center)

    // Edge vertices
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.1415926f * i / segments;
        float x = cosf(angle) * 0.5f;
        float y = sinf(angle) * 0.5f;

        // Position
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(0.0f);

        // Texture coords (map circle edge to texture edge)
        vertices.push_back(0.5f + cosf(angle) * 0.5f); // u
        vertices.push_back(0.5f + sinf(angle) * 0.5f); // v
    }

    std::vector<unsigned int> indices;
    for (int i = 1; i <= segments; i++) {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }
    auto mesh = std::make_unique<Mesh>(vertices, indices, 5);
    mesh->setUseTexture(true);
    return mesh;
}
