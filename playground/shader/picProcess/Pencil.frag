#version 330 core

// Ouput data
out vec4 color;
in vec2 uv;
uniform sampler2D tex;
//去色，变成黑白照
vec4 DisColored(vec4 color);

//均值模糊采样
vec4 MeanSample(sampler2D tex,vec2 uv);

float Gauss(float x);

//高斯模糊采样
vec4 GaussSample(sampler2D tex,vec2 uv);

vec4 Sample(sampler2D tex,vec2 uv,float fstep,float prob);

void main()
{

	// Output color = red 
	//color = vec3(uv.x,uv.y,0);
	color = texture(tex,uv);
	vec4 discolor  = DisColored(color);	
	//模糊采样
	//去色
//	vec4 sampleCol = DisColored(MeanSample(tex,uv));
	vec4 sampleCol = DisColored(GaussSample(tex,uv));	
	//反向
	vec4 reserveSam = vec4(1-sampleCol.rgb,1);

	color.rgb  = discolor.rgb + discolor.rgb*(reserveSam.rgb/sampleCol.rgb);
//	color.rgb  = discolor.rgb + discolor.rgb*(sampleCol.rgb/reserveSam.rgb);
//	color.rgb = GaussSample(tex,uv).rgb;
}

vec4 DisColored(vec4 color){
	float f =  0.299*color.r+0.587 *color.g+0.114*color.b;
	return vec4(f,f,f,1);
}

vec4 MeanSample(sampler2D tex,vec2 uv){
	//模糊采样
	//采样步长
	float fstep = 0.0015;
	vec4 sampleCol = Sample(tex,uv,fstep,1);
	return sampleCol;
}

vec4 GaussSample(sampler2D tex,vec2 uv){
	//采样步长
	float fstep = 0.0015;	
	vec4 sampleCol;
	sampleCol +=Sample(tex,uv,fstep*1,0.179);
	sampleCol +=Sample(tex,uv,fstep*2,0.334);
	sampleCol +=Sample(tex,uv,fstep*3,0.487);
	return sampleCol;
}

float Gauss(float x){
	float result = 1.0/(pow(2*3.141592,0.5))*pow(2.71828,-(x*x)/2);
	return result;
}

vec4 Sample(sampler2D tex,vec2 uv,float fstep,float prob){
	//模糊采样
	vec4 sample1,sample2,sample3,sample4;
	//采样步长
//	float fstep = 0.0015;
	sample1 = texture(tex,vec2(uv.x,uv.y+fstep));
	sample2 = texture(tex,vec2(uv.x,uv.y-fstep));
	sample3 = texture(tex,vec2(uv.x+fstep,uv.y));
	sample4 = texture(tex,vec2(uv.x-fstep,uv.y));
	vec4 sampleCol = (sample1+sample2+sample3+sample4)/4*prob;
	return sampleCol;
}