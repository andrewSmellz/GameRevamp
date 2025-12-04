#ifndef GAMEREVAMP_RENDERER_H
#define GAMEREVAMP_RENDERER_H
#include <glm/glm.hpp>

#include "engine/Mesh.h"
#include "engine/Shader.h"
#include "engine/Texture.h"

class Renderer {
public:
    Renderer();

    ~Renderer();

    static void clear();

    void draw(const Mesh &mesh, const Shader &shader, const glm::mat4 &transform,
              const Texture *texture = nullptr) const;
};


#endif //GAMEREVAMP_RENDERER_H
