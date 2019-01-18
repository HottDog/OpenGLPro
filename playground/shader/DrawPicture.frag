#version 330 core

// Ouput data
out vec4 color;
in vec2 uv;
uniform sampler2D tex;
void main()
{

	// Output color = red 
	//color = vec3(uv.x,uv.y,0);
	color = texture(tex,uv);
}