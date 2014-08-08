precision mediump float;

attribute vec4 mPosition;
attribute vec4 mColor;
attribute vec4 mNormal;

uniform vec4 uColor;
uniform vec4 uMat;

uniform mat4 uProj;
uniform mat4 uView;

varying vec4 vColor;

void main(void)
{
    gl_Position = uView * mPosition;
    vColor = uColor;
}
