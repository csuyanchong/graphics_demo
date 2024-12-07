#version 4450 core

layout(location=0) in vec3 v_in_position;

void main() {
    gl_Position = vec4(v_in_position, 1.0);
}
