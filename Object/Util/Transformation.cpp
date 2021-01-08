//
// Created by konstantin on 08.01.2021.
//

#include "Transformation.h"

Transformation::Transformation() : scale(1.0f, 1.0f, 1.0f) {
}

const glm::mat4 &Transformation::getMatrix() const {
    return matrix;
}

void Transformation::setMatrix(const glm::mat4 &matrix) {
    Transformation::matrix = matrix;
}

const glm::vec3 &Transformation::getScale() const {
    return scale;
}

void Transformation::setScale(const glm::vec3 &scale) {
    Transformation::scale = scale;
}

const glm::vec3 &Transformation::getTranslate() const {
    return translate;
}

void Transformation::setTranslate(const glm::vec3 &translate) {
    Transformation::translate = translate;
}

const glm::vec3 &Transformation::getRotate() const {
    return rotate;
}

void Transformation::setRotate(const glm::vec3 &rotate) {
    Transformation::rotate = rotate;
}

GLfloat Transformation::getAngle() const {
    return angle;
}

void Transformation::setAngle(GLfloat angle) {
    Transformation::angle = angle;
}

glm::mat4 Transformation::update() {
    matrix = glm::identity<glm::mat4>();
    if(angle != 0.0f) {
        matrix = glm::rotate(matrix, angle, rotate);
    }
    matrix = glm::translate(matrix, translate);
    matrix = glm::scale(matrix, scale);
    return matrix;
}
