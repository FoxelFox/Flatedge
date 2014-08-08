in vec4 mPosition;
in vec2 mUV;

uniform mat4 uProj;
uniform mat4 uView;
uniform mat4 uModl;
uniform mat4 uScen;

out vec2 vUV;

void main(void)
{
    gl_Position = uModl * uScen * mPosition;
    vUV = (gl_Position.xy + 1.0) * 0.5;
}
