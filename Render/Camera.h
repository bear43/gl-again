//
// Created by konstantin on 07.01.2021.
//

#ifndef UNTITLED_CAMERA_H
#define UNTITLED_CAMERA_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../Shader/ShaderProgram.h"

class Camera {
protected:
    GLfloat fov = 45.0f;
    GLuint width;
    GLuint height;
    GLfloat zNear = 0.1f;
    GLfloat zFar = 100.0f;
    glm::vec3 eye {0.0f, 0.0f, 5.0f};
    glm::vec3 center {0.0f, 0.0f, 0.0f};
    glm::vec3 up {0.0f, 1.0f, 0.0f};
    glm::mat4 projection;
    glm::mat4 view;
public:
    Camera(GLfloat fov, GLuint width, GLuint height, GLfloat zNear, GLfloat zFar, const glm::vec3 &eye,
           const glm::vec3 &center, const glm::vec3 &up);

    Camera(GLuint width, GLuint height);

    GLfloat getFov() const;

    void setFov(GLfloat fov);

    GLuint getWidth() const;

    void setWidth(GLuint width);

    GLuint getHeight() const;

    void setHeight(GLuint height);

    GLfloat getZNear() const;

    void setZNear(GLfloat zNear);

    GLfloat getZFar() const;

    void setZFar(GLfloat zFar);

    const glm::vec3 &getEye() const;

    void setEye(const glm::vec3 &eye);

    const glm::vec3 &getCenter() const;

    void setCenter(const glm::vec3 &center);

    const glm::vec3 &getUp() const;

    void setUp(const glm::vec3 &up);

    void updateProjectionMatrix();

    void updateViewMatrix();

    void draw(ShaderProgram &shaderProgram);

    static Camera& getMainCamera();

    const glm::mat4 &getProjection() const;

    const glm::mat4 &getView() const;

};


#endif //UNTITLED_CAMERA_H
