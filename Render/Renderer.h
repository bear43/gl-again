//
// Created by konstantin on 13.12.2020.
//

#ifndef UNTITLED_RENDERER_H
#define UNTITLED_RENDERER_H

#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "../Shader/Shader.h"
#include "../Shader/ShaderProgram.h"
#include "../Buffer/VAO/VAO.h"
#include "../Object/Util/OBJ_Loader.h"
#include "../Buffer/Buffer/Buffer.h"
#include "../Object/Object.h"
#include "../Object/Util/ObjectFactory.h"
#include "Camera.h"
#include <vector>

/**
 * Used for rendering smth.
 */
class Renderer {
private:
    //const GLfloat M_PI = 1.0f;// = 3.14159265358979323846;
    ShaderProgram shaderProgram;
    Object *model = nullptr;
public:
    Renderer(const std::string &vertexShaderFilename, const std::string &fragmentShaderFilename);
    virtual ~Renderer();
    void onFrameRender();
    void preCycle();
};


#endif //UNTITLED_RENDERER_H
