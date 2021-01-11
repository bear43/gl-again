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


void Cursor::onCameraMove(int deltaX, int deltaY) {
    std::cout << fmt::format("{} {}", deltaX, deltaY) << std::endl;
    glm::vec3 direction;
    yaw += static_cast<GLfloat>(deltaX);
    pitch += static_cast<GLfloat>(deltaY);
    if(pitch > 89.0f)
        pitch =  89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction *= -1;
    Camera &camera = Camera::getMainCamera();
    glm::vec3 newPosition = camera.getEye();
    GLfloat vectorLength = glm::length(newPosition);
    newPosition = direction * vectorLength;
    camera.setEye(newPosition);
    camera.updateViewMatrix();
}

void Cursor::onPosChanged(GLFWwindow *window, double x, double y) {
    _x = static_cast<int>(x);
    _y = static_cast<int>(y);
    if(oldX == -1) {
        oldX = (_x > 0) ? (_x - 1) : 0;
    }
    if(oldY == -1) {
        oldY = (_y > 0) ? (_y - 1) : 0;
    }
    if(leftMouseButtonClicked) {
        int deltaX = _x - oldX;
        int deltaY = _y - oldY;
        onCameraMove(deltaX, -deltaY);
        oldX = _x;
        oldY = _y;
    }
    glm::vec2 vec = glm::vec2(x, y);
    _ndc = glm::vec3(transformIntoNDC(vec, Camera::getMainCamera()), 1.0);
    Camera &camera = Camera::getMainCamera();
    auto &proj = const_cast<glm::mat4 &>(camera.getProjection());
    auto &view = const_cast<glm::mat4 &>(camera.getView());
    glm::mat4 projAndViewInverse = glm::inverse(proj * view * glm::translate(glm::identity<glm::mat4>(), camera.getEye()));
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

void Cursor::onScroll(GLFWwindow *window, double xoffset, double yoffset) {
    if (yoffset != 0.0) {
        Camera &mainCamera = Camera::getMainCamera();
        auto normalizedPosition = glm::normalize(const_cast<glm::vec3 &>(mainCamera.getEye()));
        glm::vec3 movementVector;
        static GLfloat step = 1.0f;
        movementVector = normalizedPosition * step;
        if(yoffset > 0) {
            movementVector *= -1;
        }

        const glm::vec3 &newPosition = movementVector + mainCamera.getEye();
        if(newPosition != glm::vec3{0.0f, 0.0f, 0.0f}) {
            mainCamera.setEye(newPosition);
            mainCamera.updateViewMatrix();
        } else {
            std::clog << "Camera newPosition in about to 0.0, 0.0, 0.0. No movement" << std::endl;
        }
    }
}

void Cursor::onClick(GLFWwindow* window, int button, int state, int modifier) {
    if(button == GLFW_MOUSE_BUTTON_LEFT) {
        if(state == GLFW_PRESS) {
            oldX = -1;
            oldY = -1;
            leftMouseButtonClicked = true;
        } else {
            leftMouseButtonClicked = false;
        }
    }
}
