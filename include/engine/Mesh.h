#ifndef GAMEREVAMP_MESH_H
#define GAMEREVAMP_MESH_H
#include <vector>

#include "glm/vec3.hpp"


class Mesh {
public:
    Mesh(const std::vector<float> &vertices, int stride);

    Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, int stride);

    ~Mesh();

    void bind() const;

    void unbind() const;

    int getVertexCount() const;

    void draw() const;

    void setColor(glm::vec3 newColor);

    glm::vec3 getColor() const;

    void setUseTexture(bool use);

    bool getUseTexture() const;

private:
    unsigned int VAO, VBO, EBO;
    int vertexCount;
    int stride;
    bool useIndices;
    int indexCount;
    glm::vec3 color;
    bool useTexture;
};


#endif //GAMEREVAMP_MESH_H
