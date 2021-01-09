//
// Created by konstantin on 08.01.2021.
//

#include "Transformation.h"

Transformation::Transformation() : matrix(glm::identity<glm::mat4>()), rotation(glm::identity<glm::mat4>()), translation(glm::identity<glm::mat4>()), scaling(glm::identity<glm::mat4>()) {
}

const glm::mat4 &Transformation::getMatrix() const {
    return matrix;
}

void Transformation::setMatrix(const glm::mat4 &matrix) {
    Transformation::matrix = matrix;
}

glm::mat4 Transformation::update() {
    matrix = translation * rotation * scaling;
    return matrix;
}

void Transformation::rotate(GLfloat angle, const glm::vec3 &axis) {
    rotation = glm::rotate(rotation, angle, axis);
}

void Transformation::translate(const glm::vec3 &vector) {
    translation = glm::translate(translation, vector);
}

void Transformation::scale(const glm::vec3 &scaleVector) {
    scaling = glm::scale(scaling, scaleVector);
}


