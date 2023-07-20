#version 330 core

layout(location = 0) out vec4 color;

//u_ is for uniform variables
uniform vec4 u_Color;

void main()
{
    color = u_Color;
}