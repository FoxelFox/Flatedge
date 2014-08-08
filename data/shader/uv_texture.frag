in vec2 vUV;

out vec4 pColor;

uniform sampler2D tColor;

void main(void) {
    pColor = texture2D(tColor, vUV);
    //pColor = vec4(vUV.x, vUV.y, 0.0, 1.0);
}
