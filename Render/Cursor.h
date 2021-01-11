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
    static inline bool leftMouseButtonClicked = false;
    static void onCameraMove(int deltaX, int deltaY);
    static inline GLfloat yaw = 90.0f, pitch = 0.0f;
    static inline int oldX = -1;
    static inline int oldY = -1;
public:
    static void onPosChanged(GLFWwindow* window, double x, double y);
    static void onScroll(GLFWwindow *window, double xoffset, double yoffset);
    static void draw(const ShaderProgram &shaderProgram);
    static void onClick(GLFWwindow* window, int button, int state, int modifier);
};


#endif //UNTITLED_CURSOR_H
