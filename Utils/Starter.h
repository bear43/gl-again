//
// Created by konstantin on 12.12.2020.
//

#ifndef UNTITLED_STARTER_H
#define UNTITLED_STARTER_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Starter {
private:
    static inline GLFWwindow* mainWindow = nullptr;
    static inline int width = -1;
    static inline int height = -1;
public:
    static int initWindow(int width, int height, std::string title);
    static int init();
    static int initGLEW();
    static GLFWwindow* getMainWindow();

    static int getWidth();

    static int getHeight();
};


#endif //UNTITLED_STARTER_H
