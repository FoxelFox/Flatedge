#version 430 core

in vec2 ex_uv;

layout(location = 0) out vec4 color;

layout(location = 0) uniform sampler2D tx_float;
layout(location = 1) uniform sampler2D tx_world;


void main(){
    float world_h = texture(tx_world, ex_uv).a;
    float float_h = texture(tx_float, ex_uv).a;
    vec2 velo = texture(tx_float, ex_uv).xy;


    float x = clamp(float_h - world_h,0.0,1.0);

    //color = vec4(velo.x,velo.y,1.0,1.0);
    //color *= length(velo);
    //color -= x;

    color = vec4(1.0);
    color.yz -= abs(length(velo)) * 2;
    color.z += x;
    color.xy -= x;

    //color = vec4(texture(tx_float, ex_uv).z);
}