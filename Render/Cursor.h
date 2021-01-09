//
// Created by konstantin on 08.01.2021.
//

#ifndef UNTITLED_CURSOR_H
#define UNTITLED_CURSOR_H

#include "Camera.h"
#include <GLFW/glfw3.h>

class Cursor {
protected:
    static inline int _x = 0;
    static inline int _y = 0;
    static inline glm::vec3 _ndc {0.0, 0.0, 0.0};
    static glm::vec2 transformIntoNDC(glm::vec2 &point, const Camera &camera);
    static inline bool hasChanged = false;
public:
    static void onPosChanged(GLFWwindow* window, double x, double y);
    static void draw(const ShaderProgram &shaderProgram);
};


#endif //UNTITLED_CURSOR_H
