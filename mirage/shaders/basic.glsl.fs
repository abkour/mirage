#version 450 core
layout(location = 0) out vec4 FragmentColor;

in vec2 uv;

uniform sampler2D color_buffer;

void main()
{
    vec3 c = texture(color_buffer, uv).rgb;
    FragmentColor = vec4(c, 1.f);
}