#version 440

layout(location = 0) in vec4 mPosition;
layout(location = 1) in vec4 mColor;
layout(location = 2) in vec4 mNormal;

uniform vec4 uColor;
uniform vec4 uMat;

layout(location = 0) out vec4 vColor;

layout(std140) uniform GlobalMatrices
{
    mat4 mat_view;
    mat4 mat_proj;
};

void main(void)
{
    gl_Position = mPosition;
    vColor = uColor;
}
