//
// Created by konstantin on 08.01.2021.
//

#include "Cursor.h"

glm::vec2 Cursor::transformIntoNDC(glm::vec2 &point, const Camera &camera) {
    auto width = static_cast<double>(camera.getWidth());
    auto height = static_cast<double>(camera.getHeight());
    auto halfWidth = width / 2.0;
    auto halfHeight = height / 2.0;
    if(halfWidth != 0.0 && halfHeight != 0.0) {
        point.x -= halfWidth; point.x /= halfWidth;
        point.y = height - point.y; point.y -= halfHeight; point.y /= halfHeight;
        return point;
    } else {
        return glm::vec2(0.0, 0.0);
    }
}

void Cursor::onPosChanged(GLFWwindow *window, double x, double y) {
    _x = static_cast<int>(x);
    _y = static_cast<int>(y);
    glm::vec2 vec = glm::vec2(x, y);
    _ndc = glm::vec3(transformIntoNDC(vec, Camera::getMainCamera()), 1.0);
    Camera &camera = Camera::getMainCamera();
    auto &proj = const_cast<glm::mat4 &>(camera.getProjection());
    auto &view = const_cast<glm::mat4 &>(camera.getView());
    glm::mat4 projAndViewInverse = glm::inverse(proj * view);
    glm::vec4 rayWor = projAndViewInverse * glm::vec4(_ndc, 1.0);;
    rayWor /= rayWor.w;
    rayWor = glm::normalize(rayWor);
    _ndc = rayWor;
    hasChanged = true;
}

void Cursor::draw(const ShaderProgram &shaderProgram) {
    if(hasChanged) {
        shaderProgram.setMousePos(_ndc);
    }
}
