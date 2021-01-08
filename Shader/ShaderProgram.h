//
// Created by konstantin on 13.12.2020.
//

#ifndef UNTITLED_SHADERPROGRAM_H
#define UNTITLED_SHADERPROGRAM_H

#include <GL/glew.h>
#include <GL/gl.h>
#include "Shader.h"
#include "../Common/IdHolder.h"
#include "../Object/Object.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class ShaderProgram : public IdHolder {
private:
    Shader vertexShader;
    Shader fragmentShader;
public:
    GLint modelLocation = -1;
    GLint viewLocation = -1;
    GLint projectionLocation = -1;
    GLint materialAmbientColorLocation = -1;
    GLint materialDiffuseColorLocation = -1;
    GLint materialSpecularColorLocation = -1;
    ShaderProgram(const Shader &vertexShader, const Shader& fragmentShader);
    virtual ~ShaderProgram();
    void setModelMatrix(const glm::mat4 &modelMatrix) const;
    void setProjectionMatrix(glm::mat4 &projectionMatrix) const;
    void setViewMatrix(glm::mat4 &viewMatrix) const;
    void use();
    void setMaterial(objl::Material &material);
};


#endif //UNTITLED_SHADERPROGRAM_H
