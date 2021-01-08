//
// Created by konstantin on 07.01.2021.
//

#include "Mesh.h"

Mesh::Mesh(objl::Mesh &mesh) : name(mesh.MeshName), indices(mesh.Indices), material(mesh.MeshMaterial),
                               vertices(mesh.Vertices) {
    vao = new VAO(fmt::format("{} VAO", name));
    vertexBuffer = new Buffer(fmt::format("{} vertex buffer", name), GL_ARRAY_BUFFER, GL_STATIC_DRAW);
    indexBuffer = new Buffer(fmt::format("{} index buffer", name), GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);
    const unsigned char totalVertexArraySize = 8;
    const unsigned long vertexBufferSize = mesh.Vertices.size() * totalVertexArraySize;
    auto *vertexBufferData = new GLfloat[vertexBufferSize];
    const unsigned long indicesBufferSize = mesh.Indices.size();
    auto *indicesBufferData = new GLuint[indicesBufferSize];
    for (int index = 0, currentElement = 0; index < mesh.Vertices.size(); index++, currentElement = 0) {
        const objl::Vertex &vertex = mesh.Vertices[index];
        vertexBufferData[totalVertexArraySize * index + currentElement++] = vertex.Position.X;
        vertexBufferData[totalVertexArraySize * index + currentElement++] = vertex.Position.Y;
        vertexBufferData[totalVertexArraySize * index + currentElement++] = vertex.Position.Z;
        vertexBufferData[totalVertexArraySize * index + currentElement++] = vertex.TextureCoordinate.X;
        vertexBufferData[totalVertexArraySize * index + currentElement++] = vertex.TextureCoordinate.Y;
        vertexBufferData[totalVertexArraySize * index + currentElement++] = vertex.Normal.X;
        vertexBufferData[totalVertexArraySize * index + currentElement++] = vertex.Normal.Y;
        vertexBufferData[totalVertexArraySize * index + currentElement] = vertex.Normal.Z;
    }
    for (int index = 0; index < mesh.Indices.size(); index++) {
        indicesBufferData[index] = mesh.Indices[index];
    }
    vertexBuffer->fill(vertexBufferSize * sizeof(GLfloat), vertexBufferData);
    indexBuffer->fill(indicesBufferSize * sizeof(GLuint), indicesBufferData);
    vao->linkWithVBO(vertexBuffer);
    vao->linkWithEBO(indexBuffer);
    texture = SOIL_load_OGL_texture(mesh.MeshMaterial.map_Kd.c_str(), 0, texture, SOIL_FLAG_INVERT_Y);
    if (!texture) {
        std::clog << fmt::format("Не удалось подгрузить тестуру {}", mesh.MeshMaterial.map_Kd) << std::endl;
    }
}

Mesh::~Mesh() {
    if (vertexBuffer != nullptr) {
        vertexBuffer->deleteBuffer();
        delete vertexBuffer;
        vertexBuffer = nullptr;
    }
    if (indexBuffer != nullptr) {
        indexBuffer->deleteBuffer();
        delete indexBuffer;
        indexBuffer = nullptr;
    }
    if (vao != nullptr) {
        vao->deleteBuffer();
        delete vao;
        vao = nullptr;
    }
    if (texture > 0) {
        glDeleteTextures(1, &texture);
    }
}

VAO *Mesh::getVao() const {
    return vao;
}

GLuint Mesh::getIndicesCount() {
    return indices.size();
}

const Transformation &Mesh::getTransformation() {
    return transformation;
}

void Mesh::bindMaterial(ShaderProgram &shaderProgram) const {
    shaderProgram.setMaterial(const_cast<objl::Material &>(material));
}

const objl::Material &Mesh::getMaterial() const {
    return material;
}

GLuint Mesh::getTexture() const {
    return texture;
}
