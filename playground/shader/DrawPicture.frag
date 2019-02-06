#version 330 core

// Ouput data
out vec4 color;
in vec2 uv;
uniform sampler2D tex;
uniform vec3 rectColor;
void main()
{

	// Output color = red 
	//color = vec3(uv.x,uv.y,0);
	color = texture(tex,uv);
	color = color*vec4(rectColor,1.0f);
}