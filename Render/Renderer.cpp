//
// Created by konstantin on 13.12.2020.
//

#include "Renderer.h"


void Renderer::onFrameRender() {
    shaderProgram.use();
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Camera::getMainCamera().draw(shaderProgram);
    Cursor::draw(shaderProgram);
    for(Object* localModel : models) {
        localModel->getTransformation().rotate(0.01f,glm::vec3(0.0f, 1.0f, 0.0f));
        localModel->getTransformation().update();
        localModel->draw(shaderProgram);
    }
}

Renderer::Renderer(const std::string &vertexShaderFilename, const std::string &fragmentShaderFilename) : shaderProgram(
        ShaderProgram(Shader(vertexShaderFilename, GL_VERTEX_SHADER), Shader(fragmentShaderFilename, GL_FRAGMENT_SHADER))) {
    ObjectFactory objectFactory("./Lowpoly_Notebook_2.obj");
    auto model = new Object(objectFactory.createFromFile("Notebook model"));
    //model->getTransformation().setScale(glm::vec3(0.01f, 0.01f, 0.01f));
    model->getTransformation().rotate(glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    models.push_back(model);
    for(int counter = 0; counter < 100; counter++) {
        auto localModel = new Object(*model);
        //localModel->getTransformation().rotate(glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        GLfloat z = random() % 100 * (random() % 2 ? -1 : 1);
        GLfloat y = random() % 20 * (random() % 2 ? -1 : 1);
        GLfloat x = random() % 100 * (random() % 2 ? -1 : 1);
        localModel->getTransformation().translate(glm::vec3(x, y, z));
        localModel->getTransformation().update();
        models.push_back(localModel);
    }
    model->getTransformation().translate(glm::vec3(1.0f, -1.0f, -3.0f));
    model->getTransformation().update();
}

Renderer::~Renderer() {
}

void Renderer::preCycle() {

}
