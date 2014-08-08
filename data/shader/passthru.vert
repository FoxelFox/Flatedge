in vec4 mPosition;
in vec4 mColor;
in vec4 mNormal;

uniform vec4 uMat;

uniform mat4 uProj;
uniform mat4 uView;

out vec4 vPosition;
out vec4 vColor;
out vec4 vNormal;

void main(void)
{
    gl_Position = uView * mPosition;
    vPosition = mPosition;
    vColor = mColor;
    vNormal = mNormal;
}
