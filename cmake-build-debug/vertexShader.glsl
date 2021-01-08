#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

struct Material {
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
};

uniform Material material;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor; // Передаем цвет во фрагментный шейдер
out vec2 texCoords;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    ourColor = material.diffuseColor; // Устанавливаем значение цвета, полученное от вершинных данных
    texCoords = texCoord;
}