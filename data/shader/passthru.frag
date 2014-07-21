#version 440

layout(location = 0) in vec4 vPosition;
layout(location = 1) in vec4 vColor;
layout(location = 2) in vec4 vNormal;


layout(location = 0) out vec4 pPosition;
layout(location = 1) out vec4 pColor;
layout(location = 2) out vec4 pNormal;

void main(void) {
    pPosition = vPosition;
    pColor = vColor;
    pNormal = vNormal;
}
 
