//
// Created by konstantin on 06.01.2021.
//

#include "Buffer.h"

void Buffer::bindBuffer() {
    glBindBuffer(target, id);
}

void Buffer::unbindBuffer() {
    glBindBuffer(target, 0);
}

Buffer::Buffer(const string &name, GLenum target, GLenum usage) : AbstractBuffer(name), usage(usage), target(target) {
    glGenBuffers(1, &id);
    buffer_created = true;
}

void Buffer::fill(GLsizei size, GLvoid *data) {
    this->size = size;
    this->data = data;
    bindBuffer();
    glBufferData(target, size, data, usage);
    unbindBuffer();
}

GLenum Buffer::getUsage() const {
    return usage;
}

void Buffer::setUsage(GLenum usage) {
    Buffer::usage = usage;
}

GLenum Buffer::getTarget() const {
    return target;
}

void Buffer::setTarget(GLenum target) {
    Buffer::target = target;
}

void Buffer::deleteBuffer() {
    glDeleteBuffers(1, &id);
}


