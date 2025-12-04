#include "engine/Texture.h"
#include <glad/glad.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(const std::string &path, bool flipVertically)
    : ID(0), width(0), height(0), channels(0), path(path) {
    load(path, flipVertically);
}

Texture::~Texture() {
    glDeleteTextures(1, &ID);
}

void Texture::load(const std::string &path, bool flipVertically) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(flipVertically);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 0);

    if (data) {
        GLenum format = GL_RGB;
        if (channels == 1)
            format = GL_RED;
        else if (channels == 3)
            format = GL_RGB;
        else if (channels == 4)
            format = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                     GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        std::cout << "Texture loaded: " << path << " (" << width << "x" << height
                << ", " << channels << " channels)" << std::endl;
    } else {
        std::cout << "ERROR::TEXTURE::FAILED_TO_LOAD: " << path << std::endl;
        std::cout << "STB Error: " << stbi_failure_reason() << std::endl;
    }

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind(unsigned int slot) const {
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Texture::getID() const { return ID; }
int Texture::getWidth() const { return width; }
int Texture::getHeight() const { return height; }
int Texture::getChannels() const { return channels; }
