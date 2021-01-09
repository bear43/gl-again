#version 420 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 viewPos;
uniform vec3 mousePosNDC;

out vec3 outPosition;
out vec2 outTexCoord;
out vec3 outNormal;
out vec3 outHovered;

void main()
{
    mat4 matmul = projection * view * model;
    gl_Position = matmul * vec4(position, 1.0);
    outPosition = gl_Position.xyz;
    outTexCoord = texCoord;
    outNormal = mat3(transpose(inverse(model))) * normal;
    vec3 normPos = normalize((view * model * vec4(position, 1.0)).xyz);
    outHovered = dot(mousePosNDC.xyz, normPos.xyz) > 0.999 ? vec3(0.1, 0.5, 0.6) : vec3(0.0, 0.0, 0.0);
}