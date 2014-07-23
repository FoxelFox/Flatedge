#version 440

layout(location = 0) in vec4 vUV;

layout(location = 0) out vec4 pColor;

uniform sampler2D tColor;

void main(void) {
    pColor = texture2D(tColor, vUV);
}