#ifndef GAMEREVAMP_RENDERER_H
#define GAMEREVAMP_RENDERER_H

#include "engine/Shader.h"

class Renderer {
public:
    Renderer();

    ~Renderer();

    static void clear();

    void drawTestTriangle(const Shader &shader) const;

private:
    unsigned int VAO, VBO;

    void testInitTriangle();
};


#endif //GAMEREVAMP_RENDERER_H
