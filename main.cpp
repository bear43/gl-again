#include "Utils/Starter.h"
#include "Render/FrameRender.h"

int main() {
    Starter::init();
    Starter::initWindow(1024, 768, "Sample");
    Starter::initGLEW();
    FrameRender::init();
    FrameRender::addRenderer(std::make_shared<Renderer>("./vertexShader.glsl", "./fragmentShader.glsl"));
    FrameRender::run();
    return 0;
}
