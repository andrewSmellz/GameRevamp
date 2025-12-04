//
// Created by andre on 2025-12-04.
//

#ifndef GAMEREVAMP_COLOURS_H
#define GAMEREVAMP_COLOURS_H
#include "glm/vec3.hpp"

namespace Colours {
    constexpr auto RED = glm::vec3(1.0f, 0.0f, 0.0f);
    constexpr auto GREEN = glm::vec3(0.0f, 1.0f, 0.0f);
    constexpr auto BLUE = glm::vec3(0.0f, 0.0f, 1.0f);

    constexpr auto YELLOW = glm::vec3(1.0f, 1.0f, 0.0f);
    constexpr auto CYAN = glm::vec3(0.0f, 1.0f, 1.0f);
    constexpr auto MAGENTA = glm::vec3(1.0f, 0.0f, 1.0f);

    constexpr auto WHITE = glm::vec3(1.0f, 1.0f, 1.0f);
    constexpr auto BLACK = glm::vec3(0.0f, 0.0f, 0.0f);
    constexpr auto GRAY = glm::vec3(0.5f, 0.5f, 0.5f);
    constexpr auto LIGHT_GRAY = glm::vec3(0.75f, 0.75f, 0.75f);
    constexpr auto DARK_GRAY = glm::vec3(0.25f, 0.25f, 0.25f);

    constexpr auto PURPLE = glm::vec3(0.5f, 0.0f, 0.5f);
    constexpr auto PINK = glm::vec3(1.0f, 0.75f, 0.8f);
    constexpr auto BROWN = glm::vec3(0.6f, 0.3f, 0.0f);
    constexpr auto ORANGE = glm::vec3(1.0f, 0.5f, 0.0f);
}

#endif //GAMEREVAMP_COLOURS_H
