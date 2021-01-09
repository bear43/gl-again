//
// Created by konstantin on 07.01.2021.
//

#include "Object.h"

Object::Object(const string &name, objl::Loader &loader) : name(name) {
    for(objl::Mesh &mesh : loader.LoadedMeshes) {
        meshes.push_back(new Mesh(mesh));
    }
}

void Object::draw(const ShaderProgram &shaderProgram) {
    static const glm::vec3 position = glm::vec3{0.0f, 3.0f, 3.0f};
    shaderProgram.setLightPos(const_cast<glm::vec3 &>(position));
    for(Mesh *mesh : meshes) {
        VAO *pVao = mesh->getVao();
        pVao->bindBuffer();
        shaderProgram.setModelMatrix(transformation.getMatrix());
        mesh->bindMaterial(const_cast<ShaderProgram &>(shaderProgram));
        if(mesh->getTexture() > 0) {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, mesh->getTexture());
        }
        glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
        glBindTexture(GL_TEXTURE_2D, 0);
        pVao->unbindBuffer();
    }
}

Object::~Object() {
    for(Mesh *mesh : meshes) {
        delete mesh;
    }
}

Transformation & Object::getTransformation() {
    return transformation;
}
