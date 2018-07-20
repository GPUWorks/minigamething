#version 330 core


// usual noise functions, from https://gist.github.com/patriciogonzalezvivo/670c22f3966e662d2f83
uniform float time;
uniform vec2  res;
out vec4 frag_colour;

float rand(float n){return fract(sin(n) * 43758.5453123);}
float rand(vec2 n) {
	return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}
float noise(float p){
	float fl = floor(p);
  float fc = fract(p);
	return mix(rand(fl), rand(fl + 1.0), fc);
}
float noise(vec2 p){
	vec2 ip = floor(p);
	vec2 u = fract(p);
	u = u*u*(3.0-2.0*u);

	float res = mix(
		mix(rand(ip),rand(ip+vec2(1.0,0.0)),u.x),
		mix(rand(ip+vec2(0.0,1.0)),rand(ip+vec2(1.0,1.0)),u.x),u.y);
	return res*res;
}

#define RADIUS 0.6
#define CORONA 0.3
#define STARCOLOR vec3(0.5, .5, 0)

float dist(vec2 p)
{
    return length(p)-RADIUS;
}

vec3 baseColor(vec2 p)
{
    return STARCOLOR*(1.0-smoothstep(.0,RADIUS/20.0,dist(p)));
}

vec3 highlight(vec2 p, vec3 base)
{
    return base*vec3(RADIUS-dist(p));
}

vec3 corona(vec2 p, vec3 base)
{
    float d = (dist(p));

    // noise on the distance
    vec2 angleVec = normalize(p);

    d = d*0.8 + 0.2*d*noise(dot(angleVec,vec2(1.0,0.0))*40.0*noise(500.0+time*0.05));

    float b = clamp((0.7-smoothstep(0.0,CORONA,d)),0.0,1.0)*0.5;

    //b*= noise(dot(normalize(p),vec2(1.0,0.0))*40.0);

    return STARCOLOR*b + base;
}

float speedfactor(vec2 p)
{
    // only care about y component
    float d = abs(p.y)/RADIUS;
    return 1.0-d;
}

void main() {
    vec2 uv=(gl_FragCoord.xy/res *2.0 - vec2(1.0)) * vec2(res.x/res.y,1.0);
    vec3 c = baseColor(uv);

    // calculates the color and the lines on the thing
    c = 0.6*c + c*vec3(noise((uv.xy+vec2(time*0.006*speedfactor(uv),0.0))*500.0));

    // creates the highlight in the center
    c = highlight(uv,c);

    c = corona(uv,c);

    frag_colour = vec4(c,1.0);

}
