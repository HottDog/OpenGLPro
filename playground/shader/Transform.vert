#version 330 core

layout(location = 0) in vec3 vertexdata;
layout(location = 1) in vec2 uvdata;
uniform mat4 transform;

out vec2 uv;


void main(){
	gl_Position = transform * vec4(vertexdata,1);
	uv = uvdata;
}