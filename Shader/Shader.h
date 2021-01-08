//
// Created by konstantin on 13.12.2020.
//

#ifndef UNTITLED_SHADER_H
#define UNTITLED_SHADER_H

#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../Common/IdHolder.h"

class Shader : public IdHolder {
private:
    std::string filename;
    GLenum type;
public:
    Shader(std::string filename, GLenum type);
    virtual ~Shader();
};


#endif //UNTITLED_SHADER_H
