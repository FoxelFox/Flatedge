#ifdef GL_ES
precision highp float;
#endif

attribute vec4 mPosition;
attribute vec2 mUV;

uniform mat4 uProj;
uniform mat4 uView;
uniform mat4 uModl;
uniform mat4 uScen;

varying vec2 vUV;

void main(void)
{
    vUV = (gl_Position.xy + 1.0) * 0.5;
    gl_Position = uModl * uScen * mPosition;
}
