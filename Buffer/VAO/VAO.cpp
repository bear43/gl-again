//
// Created by bear on 24.02.19.
//

#include "VAO.h"

VAO::VAO(const string &name) : AbstractBuffer()
{
    this->name = name;
    glGenVertexArrays(1, &id);
    this->buffer_created = true;
}

void VAO::bindBuffer()
{
    if(buffer_created) glBindVertexArray(id);
}

void VAO::unbindBuffer()
{
    glBindVertexArray(0);
}

VAO::~VAO()
{
    deleteBuffer();
}

void VAO::deleteBuffer()
{
    if(buffer_created)
    {
        glDeleteVertexArrays(1, &id);
        buffer_created = false;
    }
}

void VAO::linkWithVBO(Buffer *buffer) {
    bindBuffer();
    buffer->bindBuffer();
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    size_t bElementSize = 8 * sizeof(GLfloat);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, bElementSize, (GLvoid*)nullptr);//vertex
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, bElementSize, (GLvoid*)(3 * sizeof(GLfloat)));//texcoord
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, bElementSize, (GLvoid*)(5 * sizeof(GLfloat)));//normal
    unbindBuffer();
    buffer->unbindBuffer();
}

void VAO::linkWithEBO(Buffer *buffer) {
    bindBuffer();
    buffer->bindBuffer();
    unbindBuffer();
    buffer->unbindBuffer();
}

void VAO::linkWithMaterial(Buffer *buffer) {
    bindBuffer();
    buffer->bindBuffer();
    glEnableVertexAttribArray(3);
    glEnableVertexAttribArray(4);
    glEnableVertexAttribArray(5);
    size_t bElementSize = 9 * sizeof(GLfloat);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, bElementSize, (GLvoid*)nullptr);//ambientRGB
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, bElementSize, (GLvoid*)(3 * sizeof(GLfloat)));//diffuseRGB
    glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, bElementSize, (GLvoid*)(6 * sizeof(GLfloat)));//specularRGB
    unbindBuffer();
    buffer->unbindBuffer();
}
