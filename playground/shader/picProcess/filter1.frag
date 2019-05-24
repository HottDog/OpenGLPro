#version 330 core

// Ouput data
out vec4 color;
in vec2 uv;
uniform sampler2D tex;
uniform sampler2D tex2;
uniform sampler2D tex3;

void main()
{
	vec3 matYUVRGB1 = vec3(1.0,  0.0,   1.402);
	vec3 matYUVRGB2 = vec3(1.0, -0.344, -0.714);
	vec3 matYUVRGB3 = vec3(1.0,  1.772,  0.0);
	vec3 yuvData;
	vec3 rgbData;
	yuvData.r = texture(tex,uv).x;
	yuvData.g = texture(tex2,uv).y-0.5;
	yuvData.b = texture(tex3,uv).z-0.5;
	rgbData.r = dot(yuvData, matYUVRGB1);
	rgbData.g = dot(yuvData, matYUVRGB2);
	rgbData.b = dot(yuvData, matYUVRGB3);
	color = vec4(rgbData, 1.0);
}