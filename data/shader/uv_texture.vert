#version 440

layout(location = 0) in vec4 mPosition;
layout(location = 1) in vec2 mUV;

uniform mat4 uProj;
uniform mat4 uView;

layout(location = 0) out vec2 vUV;

void main(void)
{
    gl_Position = uView * mPosition;
    vUV = mUV;
}
