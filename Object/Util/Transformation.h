//
// Created by konstantin on 08.01.2021.
//

#ifndef UNTITLED_TRANSFORMATION_H
#define UNTITLED_TRANSFORMATION_H

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transformation {
private:
    glm::mat4 matrix;//Keeps total transformation matrix
    glm::vec3 scale;//Third to change.
    glm::vec3 translate;//Second to change.
    glm::vec3 rotate;//First to change.
    GLfloat angle = 0.0f;//Rotate angle.
public:
    Transformation();
    /**
     * Should invoke it after every transformation operation.
     * Updates final model matrix in appropriate order.
     * scale * translate * rotate; Read this line in reverse order to get whole picture.
     * @return Updated matrix.
     */
    glm::mat4 update();

    const glm::mat4 &getMatrix() const;

    void setMatrix(const glm::mat4 &matrix);

    const glm::vec3 &getScale() const;

    void setScale(const glm::vec3 &scale);

    const glm::vec3 &getTranslate() const;

    void setTranslate(const glm::vec3 &translate);

    const glm::vec3 &getRotate() const;

    void setRotate(const glm::vec3 &rotate);

    GLfloat getAngle() const;

    void setAngle(GLfloat angle);
};


#endif //UNTITLED_TRANSFORMATION_H
