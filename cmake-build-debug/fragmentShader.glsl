#version 330 core

in vec2 texCoords;
out vec4 color;

struct Material {
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
};

uniform Material material;
uniform sampler2D textureSampler;

void main()
{
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * material.ambientColor;

    color = vec4(ambient, 1.0) * texture(textureSampler, texCoords);
}