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
    glm::mat4 rotation;
    glm::mat4 translation;
    glm::mat4 scaling;
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

    void rotate(GLfloat angle, const glm::vec3 &axis);

    void translate(const glm::vec3 &vector);

    void scale(const glm::vec3 &scaleVector);
};


#endif //UNTITLED_TRANSFORMATION_H
