#version 330 core

// Ouput data
out vec4 color;
in vec2 uv;
uniform sampler2D text;   //����ɫͨ��(r)������λͼ����
uniform vec3 texColor;   //���������ı���������ɫ
void main()
{

	// Output color = red 
	//color = vec3(uv.x,uv.y,0);
	//��ͨ������λͼȡ������ɫֵ��Ϊalphaֵ
	//�����ĵط���alphaȡֵΪ0������ʾ��
	//����ĵط���alphaȡֵΪ1����ʾ
	//Ȼ��texColor�����������ɫ
	color = vec4(texColor.r,texColor.g,texColor.b,texture(text,vec2(uv.x,1-uv.y)).r);
}