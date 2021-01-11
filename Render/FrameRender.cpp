//
// Created by konstantin on 13.12.2020.
//

#include "FrameRender.h"

void FrameRender::init() {
    glfwSetInputMode(Starter::getMainWindow(), GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetWindowSizeCallback(Starter::getMainWindow(), FrameRender::onResizeWindow);
    glfwSetCursorPosCallback(Starter::getMainWindow(), Cursor::onPosChanged);
    glfwSetMouseButtonCallback(Starter::getMainWindow(), Cursor::onClick);
    glfwSetScrollCallback(Starter::getMainWindow(), Cursor::onScroll);
    onResizeWindow(Starter::getMainWindow(), Starter::getWidth(), Starter::getHeight());
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_TEXTURE_2D);
    std::cout << "Инициализация рендеринга произведена" << std::endl;
}

void FrameRender::run() {
    for(std::shared_ptr<Renderer>& rendererPtr : renderers) {
        rendererPtr->preCycle();
    }
    std::cout << "Вход в цикл рендеринга" << std::endl;
    do {

        for(std::shared_ptr<Renderer>& rendererPtr : renderers) {
            rendererPtr->onFrameRender();
        }
        glfwSwapBuffers(Starter::getMainWindow());
        glfwPollEvents();
    } while (glfwGetKey(Starter::getMainWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(Starter::getMainWindow()) == 0);
    std::cout << "Цикл отрисовки покинут" << std::endl;
}

void FrameRender::addRenderer(const std::shared_ptr<Renderer>& renderer) {
    renderers.push_back(renderer);
}

void FrameRender::deleteRenderer(const std::shared_ptr<Renderer>& renderer) {
    renderers.erase(std::remove(renderers.begin(), renderers.end(), renderer), renderers.end());
}

void FrameRender::onResizeWindow(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    Camera::getMainCamera().setWidth(width);
    Camera::getMainCamera().setHeight(height);
    Camera::getMainCamera().updateProjectionMatrix();
}


