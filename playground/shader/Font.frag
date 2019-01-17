#version 330 core

// Ouput data
out vec4 color;
in vec2 uv;
uniform sampler2D text;   //单颜色通道(r)的字形位图纹理
uniform vec3 texColor;   //用来调整文本的最终颜色
void main()
{

	// Output color = red 
	//color = vec3(uv.x,uv.y,0);
	//把通过字形位图取到的颜色值作为alpha值
	//背景的地方，alpha取值为0，不显示，
	//字体的地方，alpha取值为1，显示
	//然后texColor就是字体的颜色
	color = vec4(texColor.r,texColor.g,texColor.b,texture(text,vec2(uv.x,1-uv.y)).r);
}