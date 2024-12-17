#version 450 core

layout(location = 0) in vec3 v_in_position;
layout(location = 1) in vec3 v_in_normal;
layout(location = 2) in vec2 v_in_uv;

uniform mat4 u_mvp;

out vec2 v_out_uv;

void main() {
    vec4 pos = u_mvp * vec4(v_in_position, 1.0);
    gl_Position = pos;
    v_out_uv = v_in_uv;
}
