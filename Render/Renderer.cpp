//
// Created by konstantin on 13.12.2020.
//

#include "Renderer.h"


void Renderer::onFrameRender() {
    shaderProgram.use();
    glClearColor(0.f, 0.f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    static GLfloat angle = 0.0f;
    if(angle >= 2 * M_PI) {
        angle = 0.0f;
    }
    model->getTransformation().setAngle(angle += 0.01f);
    model->getTransformation().setRotate(glm::vec3(0.0f, 1.0f, 0.0f));
    model->getTransformation().update();
    Camera::getMainCamera().draw(shaderProgram);
    model->draw(shaderProgram);
}

Renderer::Renderer(const std::string &vertexShaderFilename, const std::string &fragmentShaderFilename) : shaderProgram(
        ShaderProgram(Shader(vertexShaderFilename, GL_VERTEX_SHADER), Shader(fragmentShaderFilename, GL_FRAGMENT_SHADER))) {
    ObjectFactory objectFactory("./Lowpoly_Notebook_2.obj");
    model = new Object(objectFactory.createFromFile("Notebook model"));
    //model->getTransformation().setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    model->getTransformation().setTranslate(glm::vec3(0.0f, -1.0f, 0.0f));
}

Renderer::~Renderer() {
    if(model != nullptr) {
        delete model;
        model = nullptr;
    }
}

void Renderer::preCycle() {

}
