#ifdef GL_ES
precision highp float;
#endif

varying vec2 vUV;
uniform sampler2D tColor;

void main(void) {
    gl_FragColor = texture2D(tColor, vUV);
    gl_FragColor = vec4(vUV.x, vUV.y, 0.0, 1.0);
}
