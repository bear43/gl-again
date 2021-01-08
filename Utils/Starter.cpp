//
// Created by konstantin on 12.12.2020.
//

#include "Starter.h"

int Starter::init() {
    if(!glfwInit()) {
        std::clog << "Ошибка при инициализации GLFW" << std::endl;
        return -1;
    }
    return 0;
}

int Starter::initWindow(int width, int height, std::string title) {
    Starter::width = width;
    Starter::height = height;
    mainWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(mainWindow == nullptr) {
        std::clog << "Не удалось создать окно" << std::endl;
        glfwTerminate();
        return -1;
    }
    return 0;
}

int Starter::initGLEW() {
    glfwMakeContextCurrent(mainWindow);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) {
        std::clog << "Не удалось проинициализировать GLEW" << std::endl;
        return -1;
    }
    return 0;
}

GLFWwindow *Starter::getMainWindow() {
    return mainWindow;
}

int Starter::getWidth() {
    return width;
}

int Starter::getHeight() {
    return height;
}
