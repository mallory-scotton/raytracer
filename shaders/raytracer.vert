#version 330 core

// Get the vertex position
layout (location = 0) in vec3 vertexPos;

// Get the vertex UV position
layout (location = 1) in vec2 vertexUV;

// Exporting the UV position
out vec2 fragUV;

// Set the gl_Position to be the vertex position
void main()
{
    fragUV = vertexUV;
    gl_Position = vec4(vertexPos.xyz, 1.0);
}
