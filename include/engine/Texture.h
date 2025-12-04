

#ifndef GAMEREVAMP_TEXTURE_H
#define GAMEREVAMP_TEXTURE_H
#include <string>


class Texture {
public:
    Texture(const std::string &path, bool flipVertically = true);

    ~Texture();

    void bind(unsigned int slot = 0) const;

    void unbind() const;

    unsigned int getID() const;

    int getWidth() const;

    int getHeight() const;

    int getChannels() const;

private:
    unsigned int ID;
    int width, height, channels;
    std::string path;

    void load(const std::string &path, bool flipVertically);
};


#endif //GAMEREVAMP_TEXTURE_H
