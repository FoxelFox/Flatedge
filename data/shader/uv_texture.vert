#version 440

layout(location = 0) in vec4 mPosition;
layout(location = 1) in vec2 mUV;

uniform mat4 uProj;
uniform mat4 uView;
uniform mat4 uModl;
uniform mat4 uScen;

layout(location = 0) out vec2 vUV;

void main(void)
{
    gl_Position = uModl * uScen * mPosition;
    vUV = (gl_Position.xy + 1.0) * 0.5;
}
