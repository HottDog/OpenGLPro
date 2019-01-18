//float4 main( float4 pos : POSITION ) : SV_POSITION
//{
//	return pos;
//}

#version 330 core

// Input vertex data, different for all executions of this shader.
// Notice that the "0" here equals the "0" in glVertexAttribPointer
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 2) in vec2 vertexcolor;
// Notice that the "1" here equals the "1" in glVertexAttribPointer
//layout(location = 1) in vec3 vertexColor;
//layout(location = 1) in vec2 vertexUV;

out vec3 fragmentColor;
//out vec2 UV;   //��UV����Ƭ����ɫ��
			   //�ⲿ����
uniform mat4 MVP;

void main() {
	gl_Position = MVP * vec4(vertexPosition_modelspace, 1);
	//fragmentColor = vertexColor;
//	UV = vertexUV;
//	gl_Position.xyz = vertexPosition_modelspace;
//	gl_Position.w = 1.0;
	fragmentColor.xy = vertexcolor;
	fragmentColor.z = 0.0f;
}