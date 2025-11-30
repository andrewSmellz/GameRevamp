
#ifndef GAMEREVAMP_SHADER_H
#define GAMEREVAMP_SHADER_H


#include <string>


class Shader {
public:
    Shader(const std::string &vertexPath, const std::string &fragmentPath);

    ~Shader();

    void use() const;

    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

private:
    unsigned int ID;

    static void checkCompileErrors(unsigned int shader, const std::string &type);
};


#endif //GAMEREVAMP_SHADER_H
