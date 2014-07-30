#version 430 core

in vec2 ex_uv;

layout(location = 0) out vec4 color;

layout(location = 0) uniform sampler2D tx_float;
layout(location = 1) uniform sampler2D tx_world;

vec4 textureRND2D(vec2 uv){
	uv = floor(fract(uv)*1e3);
	float v = uv.x+uv.y*1e3;
	return fract(1e5*sin(vec4(v*1e-2, (v+1.)*1e-2, (v+1e3)*1e-2, (v+1e3+1.)*1e-2)));
}

float noise(vec2 p) {
	vec2 f = fract(p*1e3);
	vec4 r = textureRND2D(p);
	f = f*f*(3.0-2.0*f);
	return (mix(mix(r.x, r.y, f.x), mix(r.z, r.w, f.x), f.y));	
}

float cloud(vec2 p) {
	float v = 0.0;
	v += noise(p*1.)*.50000;
	v += noise(p*2.)*.25000;
	v += noise(p*4.)*.12500;
	v += noise(p*8.)*.06250;
	v += noise(p*16.)*.03125;
	return v*v*v;
}

void main(){
    float world_h = texture(tx_world, ex_uv).a;
    float float_h = texture(tx_float, ex_uv).a;

    float x = clamp(float_h - world_h,0.0,1.0);

    color.a = vec4(cloud(ex_uv * 0.01337)).a;
    color.rgb = texture(tx_world, ex_uv).rgb;

    if(x > 0.2){
    	color.g += clamp(x, 0.0, 1.0) * 0.125;
    	color.r -= clamp(x, 0.0, 1.0) * 0.125;
    } else if (x < 0.01) {
    	//color.g -= clamp(x, 0.0, 1.0);
    	color.r += clamp(x, 0.0, 1.0);
	}

    //color = vec4(0.5);
}