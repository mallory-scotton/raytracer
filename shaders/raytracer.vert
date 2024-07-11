#version 330 core

// Get the vertex position
layout (location = 0) in vec3 vertexPos;

// Set the gl_Position to be the vertex position
void main()
{
    gl_Position = vec4(vertexPos.xyz, 1.0);
}
