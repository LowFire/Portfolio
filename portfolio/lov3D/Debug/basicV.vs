#version 330 core

layout (location = 0) in vec3 posData;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 tex;

out vec3 aNormal;
out vec3 fragPos;
out vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(posData, 1.0);
	fragPos = vec3(model * vec4(posData, 1.0));
	aNormal = vec3(model * vec4(normal, 0.0));
	texCoords = tex;
}