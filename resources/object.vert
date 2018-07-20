#version 330 core
layout (location=0) in vec3 vp;
layout (location=1) in vec3 inUv;
uniform vec3 position;
uniform vec3 camera;
uniform vec2 res;
uniform float zRotation;

out vec2 uv;

void main() {
    vec3 rotated = vec3(vp.x*cos(zRotation)-vp.y*sin(zRotation), vp.x*sin(zRotation)+vp.y*cos(zRotation), vp.z);
    vec3 objectMovement = rotated + position;
    vec3 worldPosition = objectMovement - camera;
    //gl_Position = vec4(worldPosition,1.0);
    gl_Position = vec4(worldPosition.x,worldPosition.y*res.x/res.y,worldPosition.z, 1.0);
    uv = inUv.xy;
}
