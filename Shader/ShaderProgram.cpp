//
// Created by konstantin on 13.12.2020.
//

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const Shader &vertexShader, const Shader& fragmentShader) : IdHolder(), vertexShader(vertexShader), fragmentShader(fragmentShader) {
    id = glCreateProgram();
    glAttachShader(id, vertexShader.getId());
    glAttachShader(id, fragmentShader.getId());
    glLinkProgram(id);
    glBindAttribLocation(id, 0, "position");
    glBindAttribLocation(id, 1, "texCoord");
    glBindAttribLocation(id, 2, "normal");
    modelLocation = glGetUniformLocation(id, "model");
    viewLocation = glGetUniformLocation(id, "view");
    projectionLocation = glGetUniformLocation(id, "projection");
    materialAmbientColorLocation = glGetUniformLocation(id, "material.ambientColor");
    materialDiffuseColorLocation = glGetUniformLocation(id, "material.diffuseColor");
    materialSpecularColorLocation = glGetUniformLocation(id, "material.specularColor");
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(id);
}

void ShaderProgram::use() {
    glUseProgram(id);
}

void ShaderProgram::setModelMatrix(const glm::mat4 &modelMatrix) const {
    glUniformMatrix4fv(modelLocation, 1, false, &modelMatrix[0][0]);
}

void ShaderProgram::setProjectionMatrix(glm::mat4 &projectionMatrix) const {
    glUniformMatrix4fv(projectionLocation, 1, false, &projectionMatrix[0][0]);
}

void ShaderProgram::setViewMatrix(glm::mat4 &viewMatrix) const {
    glUniformMatrix4fv(viewLocation, 1, false, &viewMatrix[0][0]);
}

void ShaderProgram::setMaterial(objl::Material &material) {
    glUniform3fv(materialAmbientColorLocation, 1, &glm::vec3(material.Ka.X, material.Ka.Y, material.Ka.Z)[0]);
    glUniform3fv(materialDiffuseColorLocation, 1, &glm::vec3(material.Kd.X, material.Kd.Y, material.Kd.Z)[0]);
    glUniform3fv(materialSpecularColorLocation, 1, &glm::vec3(material.Ks.X, material.Ks.Y, material.Ks.Z)[0]);
}
