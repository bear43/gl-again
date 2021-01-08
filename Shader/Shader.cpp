//
// Created by konstantin on 13.12.2020.
//

#include "Shader.h"

Shader::Shader(std::string filename, GLenum type) : IdHolder(), filename(std::move(filename)), type(type) {
    id = glCreateShader(type);
    std::ifstream stream(this->filename);
    std::stringstream str;
    str << stream.rdbuf();
    stream.close();
    const std::basic_string<char> &copiedStr = std::string(str.str());
    const GLchar* code = copiedStr.c_str();
    glShaderSource(id, 1, &code, nullptr);
    glCompileShader(id);
    GLint success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    GLchar msg[512];
    if(!success)
    {
        glGetShaderInfoLog(id, 512, nullptr, msg);
        std::cout << "Shader has not been compiled!\n" << msg << std::endl;
    }
}

Shader::~Shader() {
    glDeleteShader(id);
}
