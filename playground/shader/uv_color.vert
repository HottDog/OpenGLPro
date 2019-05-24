#version 330 core
layout(location = 0 ) in vec3 pos ;
layout(location = 1) in vec2 uv_color;
uniform mat4 MVP;
out vec3 fragColor ;
void main(){
	gl_Position = MVP*vec4(pos,1);
	fragColor = vec3(uv_color,0);
}
