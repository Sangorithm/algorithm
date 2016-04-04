#version 150

in vec4 vPosition;
in vec4 inColor;
out vec4 Color;

void
main()
{
    gl_Position = vPosition;
	Color = inColor;
}