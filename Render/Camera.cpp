//
// Created by konstantin on 07.01.2021.
//

#include "Camera.h"

Camera::Camera(GLfloat fov, GLuint width, GLuint height, GLfloat zNear, GLfloat zFar, const glm::vec3 &eye,
               const glm::vec3 &center, const glm::vec3 &up) : fov(fov), width(width), height(height), zNear(zNear),
                                                               zFar(zFar), eye(eye), center(center), up(up) {
    updateProjectionMatrix();
    updateViewMatrix();
}

Camera::Camera(GLuint width, GLuint height) : width(width), height(height) {
    updateProjectionMatrix();
    updateViewMatrix();
}

GLfloat Camera::getFov() const {
    return fov;
}

void Camera::setFov(GLfloat fov) {
    Camera::fov = fov;
}

GLuint Camera::getWidth() const {
    return width;
}

void Camera::setWidth(GLuint width) {
    Camera::width = width;
}

GLuint Camera::getHeight() const {
    return height;
}

void Camera::setHeight(GLuint height) {
    Camera::height = height;
}

GLfloat Camera::getZNear() const {
    return zNear;
}

void Camera::setZNear(GLfloat zNear) {
    Camera::zNear = zNear;
}

GLfloat Camera::getZFar() const {
    return zFar;
}

void Camera::setZFar(GLfloat zFar) {
    Camera::zFar = zFar;
}

const glm::vec3 &Camera::getEye() const {
    return eye;
}

void Camera::setEye(const glm::vec3 &eye) {
    Camera::eye = eye;
}

const glm::vec3 &Camera::getCenter() const {
    return center;
}

void Camera::setCenter(const glm::vec3 &center) {
    Camera::center = center;
}

const glm::vec3 &Camera::getUp() const {
    return up;
}

void Camera::setUp(const glm::vec3 &up) {
    Camera::up = up;
}

void Camera::updateProjectionMatrix() {
    projection = glm::perspectiveFov(fov, static_cast<GLfloat>(width), static_cast<GLfloat>(height), zNear, zFar);
}

void Camera::updateViewMatrix() {
    view = glm::lookAt(eye, center, up);
}

void Camera::draw(ShaderProgram &shaderProgram) {
    shaderProgram.setProjectionMatrix(projection);
    shaderProgram.setViewMatrix(view);
    shaderProgram.setViewPos(eye);
}

Camera &Camera::getMainCamera() {
    static Camera mainCamera(1024, 768);
    return mainCamera;
}

const glm::mat4 &Camera::getProjection() const {
    return projection;
}

const glm::mat4 &Camera::getView() const {
    return view;
}
