#version 440

layout(location = 0) in vec4 vColor;

layout(location = 0) out vec4 pColor;

void main(void) {
    pColor = vColor;
}
