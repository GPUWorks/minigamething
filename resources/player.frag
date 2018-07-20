#version 330 core

uniform float time;
out vec4 frag_colour;

in vec2 uv;

#define PI           3.14159265358979323846

#define basecolor vec3(.04,.015,.5)

float box(vec2 p, vec2 b)
{
    vec2 d = abs(p) - b;
    return min(max(d.x,d.y),0.0) + length(max(d,0.0));
}

float triangle( vec2 p, float h)
{
    vec2 q = abs(p);
    return max(q.x*0.866025+p.y*0.5,0.0-p.y)-h*0.5;
}

float otherTriangle( vec2 p, float h)
{
    p.y = -p.y;
    vec2 q = abs(p);
    return max(q.x*0.866025+p.y*0.5,0.0-p.y)-h*0.5;
}

float angle(vec2 v)
{
    return dot(normalize(v),vec2(1.0,0.0));
}

vec2 move(vec2 p, float x, float y)
{
    return p + vec2(x,y);
}

float model(vec2 p)
{
    return min(
        min(box(p,vec2(0.258,0.5)),triangle(move(p,0.0,-0.64),0.3)),
        otherTriangle(move(p,0.0,0.64),0.3)
        );
}

void main() {
    vec2 p = uv * 2.0 - vec2(1.0);

    vec4 c = vec4(basecolor, 1.0-smoothstep(0.00,0.01,model(p)));

    frag_colour = c;
}
