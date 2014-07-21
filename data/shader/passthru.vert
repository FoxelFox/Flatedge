 #version 440

layout(location = 0) in vec4 mPosition;
layout(location = 1) in vec4 mColor;
layout(location = 2) in vec4 mNormal;

uniform vec4 uMat;

uniform mat4 uProj;
uniform mat4 uView;

layout(location = 0) out vec4 vPosition;
layout(location = 1) out vec4 vColor;
layout(location = 2) in vec4 vNormal;

layout(std140) uniform GlobalMatrices
{
    mat4 mat_view;
    mat4 mat_proj;
};

void main(void)
{
    gl_Position = uView * mPosition;
    vPosition = mPosition;
    vColor = mColor;
    vNormal = mNormal;
}