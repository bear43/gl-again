//
// Created by konstantin on 13.12.2020.
//

#include "IdHolder.h"

GLuint IdHolder::getId() const {
    return id;
}

void IdHolder::setId(GLuint id) {
    this->id = id;
}

GLuint *IdHolder::getIdPointer() {
    return &id;
}
