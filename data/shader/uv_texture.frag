#version 440

layout(location = 0) in vec2 vUV;

layout(location = 0) out vec4 pColor;

uniform sampler2D tColor;

void main(void) {
    pColor = texture2D(tColor, vUV);
    //pColor = vec4(vUV.x, vUV.y, 0.0, 1.0);
}
