#version 450 core

in vec2 v_out_uv;

layout (location = 0) out vec4 color;

uniform sampler2D material_diffuse;

void main() {
    color = texture(material_diffuse, v_out_uv);
}