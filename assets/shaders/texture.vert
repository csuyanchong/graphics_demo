#version 450 core

layout(location = 0) in vec3 v_in_position;
layout(location = 1) in vec3 v_in_normal;
layout(location = 2) in vec2 v_in_uv;

out vec2 v_out_uv;

void main() {
    gl_Position = vec4(v_in_position, 1.0);
    v_out_uv = v_in_uv;
}
