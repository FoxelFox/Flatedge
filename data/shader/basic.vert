#ifdef GL_ES
precision highp float;
#endif


attribute vec4 mPosition;
attribute vec4 mColor;
attribute vec4 mNormal;

uniform vec4 uColor;
uniform vec4 uMat;

uniform mat4 uProj;
uniform mat4 uView;
uniform mat4 uScen;
uniform mat4 uModl;

varying vec4 vColor;

void main(void)
{
    gl_Position =  uProj * uView * mPosition;
    vColor = uColor;
}
