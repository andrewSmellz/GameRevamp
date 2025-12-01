#ifndef GAMEREVAMP_MESH_H
#define GAMEREVAMP_MESH_H
#include <vector>


class Mesh {
public:
    Mesh(const std::vector<float> &vertices, int stride);

    Mesh(const std::vector<float> &vertices, const std::vector<unsigned int> &indices, int stride);

    ~Mesh();

    void bind() const;

    void unbind() const;

    int getVertexCount() const;

    void draw() const;

private:
    unsigned int VAO, VBO, EBO;
    int vertexCount;
    int stride;
    bool useIndices;
    int indexCount;
};


#endif //GAMEREVAMP_MESH_H
