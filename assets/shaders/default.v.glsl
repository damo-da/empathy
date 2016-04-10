#version 330 core

layout (location = 0) in vec3 position;

uniform float marginLeft;
uniform float marginTop;

void main()
{
  gl_Position = vec4(position.x + marginLeft, position.y + marginTop, position.z, 1.0);
}