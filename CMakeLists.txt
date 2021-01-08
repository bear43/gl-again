cmake_minimum_required(VERSION 3.17)
project(untitled)

link_libraries(-lGL -lGLEW -lglfw -lfmt -lSOIL)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp Utils/Starter.cpp Utils/Starter.h Render/Renderer.cpp Render/Renderer.h Render/FrameRender.cpp Render/FrameRender.h Shader/Shader.cpp Shader/Shader.h Shader/ShaderProgram.cpp Shader/ShaderProgram.h Common/IdHolder.cpp Common/IdHolder.h
        Buffer/VAO/VAO.h Buffer/VAO/VAO.cpp Buffer/Buffer/Buffer.cpp Buffer/Buffer/Buffer.h Object/Util/OBJ_Loader.h Object/Mesh/Mesh.cpp Object/Mesh/Mesh.h Object/Object.cpp Object/Object.h Object/Util/ObjectFactory.cpp Object/Util/ObjectFactory.h Render/Camera.cpp Render/Camera.h Object/Util/Transformation.cpp Object/Util/Transformation.h)