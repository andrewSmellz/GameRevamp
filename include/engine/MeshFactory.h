
#ifndef GAMEREVAMP_MESHFACTORY_H
#define GAMEREVAMP_MESHFACTORY_H
#include <memory>
#include "Mesh.h"


class MeshFactory {
public:
    static std::unique_ptr<Mesh> generateTriangle();

    static std::unique_ptr<Mesh> generateRectangle();

    static std::unique_ptr<Mesh> generateCircle(int segments);
};


#endif //GAMEREVAMP_MESHFACTORY_H
