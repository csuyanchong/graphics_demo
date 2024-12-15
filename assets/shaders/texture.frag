#version 450 core

in vec2 v_out_uv;

layout (location = 0) out vec4 color;

uniform sampler2D texture_sample;

void main() {
    color = texture(texture_sample, v_out_uv);
}