in vec4 vPosition;
in vec4 vColor;
in vec4 vNormal;


out vec4 pPosition;
out vec4 pColor;
out vec4 pNormal;

void main(void) {
    pPosition = vPosition;
    pColor = vColor;
    pNormal = vNormal;
}
 
