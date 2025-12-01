#ifndef GAMEREVAMP_RENDERER_H
#define GAMEREVAMP_RENDERER_H
#include <glm/glm.hpp>

#include "Mesh.h"
#include "engine/Shader.h"

class Renderer {
public:
    Renderer();

    ~Renderer();

    static void clear();

    void draw(const Mesh &mesh, const Shader &shader, const glm::mat4 &transform) const;
};


#endif //GAMEREVAMP_RENDERER_H
