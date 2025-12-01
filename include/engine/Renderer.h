#ifndef GAMEREVAMP_RENDERER_H
#define GAMEREVAMP_RENDERER_H
#include <glm/glm.hpp>
#include "engine/Shader.h"

class Renderer {
public:
    Renderer();

    ~Renderer();

    static void clear();

    void drawTriangle(const Shader &shader, const glm::mat4 &transform) const;

private:
    unsigned int VAO, VBO;

    void testInitTriangle();
};


#endif //GAMEREVAMP_RENDERER_H
