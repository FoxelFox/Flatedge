layout(location = 0) in vec4 position;

layout(std140) uniform GlobalMatrices
{
    mat4 mat_view;
    mat4 mat_proj;
};

void main(void)
{
    gl_Position =  mat_view * position;
}
