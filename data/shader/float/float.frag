in vec2 ex_uv;

out vec4 color;

uniform sampler2D tx_float;
uniform sampler2D tx_world;
uniform vec4 mouse;

// returns the fluid info
// vec4 components:
// x -- velocity.x
// y -- velocity.y
// z -- unused
// w -- fluid height
vec4 fluidInfo(ivec2 point){
	return texelFetch(tx_float, point, 0);	 
}

float terrainHeight(ivec2 point){
	return texelFetch(tx_world, point, 0).a;
}

vec4 getFloating(vec4 wi){
	vec4 f = vec4(0.0);
	ivec2 pix = ivec2(gl_FragCoord.xy);

	ivec2 uv_r = pix + ivec2(1, 0);
	ivec2 uv_l = pix - ivec2(1, 0);
	ivec2 uv_u = pix + ivec2(0, 1);
	ivec2 uv_d = pix - ivec2(0, 1);

	vec4 wir = fluidInfo(uv_r);
	vec4 wil = fluidInfo(uv_l);
	vec4 wiu = fluidInfo(uv_u);
	vec4 wid = fluidInfo(uv_d);

	// Watter height difference
	float dr = wi.a - wir.a;
	float dl = wi.a - wil.a;
	float du = wi.a - wiu.a;
	float dd = wi.a - wid.a;

	// vectoring
	f.xy += wir.xy + wil.xy + wiu.xy + wid.xy;

	if(terrainHeight(pix) < wir.a){ // fill in from right
		f.x -= dr;
		//f.a -= dr;
	}
	if(terrainHeight(pix) < wil.a){ // fill in from left
		f.x += dl;
		//f.a -= dl;
	}
	if(terrainHeight(pix) < wiu.a){ // fill in from up
		f.y -= du;
		//f.a -= du;
	}
	if(terrainHeight(pix) < wid.a){ // fill in from down
		f.y += dd;
		//f.a -= dd;
	}

	f.a += dot(wir.xy, + vec2(1.0, 0.0));
	f.a += dot(wil.xy, - vec2(1.0, 0.0));
	f.a += dot(wiu.xy, + vec2(0.0, 1.0));
	f.a += dot(wid.xy, - vec2(0.0, 1.0));

	return f;
}

void main(){

	// load floating data
    vec4 h = fluidInfo(ivec2(gl_FragCoord.xy));

    // make new water
    float dist = distance(gl_FragCoord.xy, mouse.xy);
    if(mouse.z > 0.5 && dist <  25){
    	h.a = terrainHeight(ivec2(gl_FragCoord.xy)) + cos(dist / 25) * 0.5;
    	clamp(h.a, 0.0, 1.0);
    }

    // calculate floating
    vec4 f = getFloating(h) * 0.25;
    h.xy = f.xy;
    h.a += f.a;

	// seeping water
    //h.a -= 0.000002;

    // damping velocity
    h.xy *= 0.99;
	clamp(h.a, 0.0, 50.0);

    if(mouse.w > 0.5 && dist <  25){
		h = vec4(0.0);
    	//clamp(h.a, 0.0, 1.0);
    }

    color = vec4(h);
}
