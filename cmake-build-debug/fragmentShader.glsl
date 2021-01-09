#version 420 core

in vec3 outPosition;
in vec2 outTexCoord;
in vec3 outNormal;
in vec3 outHovered;
out vec4 color;

struct Material {
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
};

uniform Material material;
uniform sampler2D textureSampler;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 mousePosNDC;

//Phong lighting.
void main()
{

    //Ambient part
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * material.ambientColor;


    vec3 norm = normalize(outNormal);
    vec3 lightDir = normalize(lightPos - outPosition);

    //Diffuse part
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * material.diffuseColor;

    //Specular part
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - outPosition);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * material.specularColor;

    //Final
    color = vec4(ambient + diffuse + specular + outHovered, 1.0) * texture(textureSampler, outTexCoord);
}