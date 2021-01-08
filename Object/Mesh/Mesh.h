//
// Created by konstantin on 07.01.2021.
//

#ifndef UNTITLED_MESH_H
#define UNTITLED_MESH_H

#include "../../Buffer/VAO/VAO.h"
#include "../../Buffer/Buffer/Buffer.h"
#include "../Util/OBJ_Loader.h"
#include "../Util/Transformation.h"
#include "../../Shader/ShaderProgram.h"
#include <string>
#include <vector>
#include <fmt/format.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ShaderProgram;

class Mesh {
protected:
    std::string name;
    Buffer *vertexBuffer = nullptr;
    Buffer *indexBuffer = nullptr;
    VAO *vao = nullptr;
    std::vector<GLuint> indices;
    std::vector<objl::Vertex> vertices;
    objl::Material material;
    GLuint texture = 0;
    Transformation transformation;
public:
    Mesh(objl::Mesh &mesh);
    virtual ~Mesh();
    VAO *getVao() const;
    GLuint getIndicesCount();
    const Transformation &getTransformation();
    void bindMaterial(ShaderProgram &shaderProgram) const;

    const objl::Material &getMaterial() const;

    GLuint getTexture() const;
};


#endif //UNTITLED_MESH_H
