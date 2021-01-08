//
// Created by konstantin on 07.01.2021.
//

#ifndef UNTITLED_OBJECT_H
#define UNTITLED_OBJECT_H

#include "Mesh/Mesh.h"
#include "../Shader/ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL/SOIL.h>

class Mesh;
class ShaderProgram;

class Object {
protected:
    std::string name;
    std::vector<Mesh*> meshes;
    Transformation transformation;
public:
    Object(const string &name, objl::Loader &loader);

    virtual ~Object();

    Transformation & getTransformation();

    void draw(const ShaderProgram &shaderProgram);
};


#endif //UNTITLED_OBJECT_H
