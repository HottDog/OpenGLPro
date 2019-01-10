//float4 main() : SV_TARGET
//{
//	return float4(1.0f, 1.0f, 1.0f, 1.0f);
//}

#version 330 core

// Interpolated values from the vertex shaders
in vec3 fragmentColor;
//Interpolated value from the vertex shaders
//in vec2 UV;
// Ouput data
out vec3 color;

//uniform sampler2D myTextureSampler;

void main() {

	// Output color = color specified in the vertex shader, 
	// interpolated between all 3 surrounding vertices
	color = fragmentColor;
	//color = fragmentColor;

//	color = texture(myTextureSampler, UV).rgb;
}