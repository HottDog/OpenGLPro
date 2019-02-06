#include"shadertool.h"
void SetShaderData(GLuint shader, char * key, const float value) {
	glUniform1f(glGetUniformLocation(shader, key), value);
}

void SetShaderData(GLuint shader, char * key, const vec2 value) {
	glUniform2f(glGetUniformLocation(shader, key), value.x, value.y);
}

void SetShaderData(GLuint shader,char * key, const vec3 value) {
	glUniform3f(glGetUniformLocation(shader, key), value.x, value.y, value.z);
}

void SetShaderData(GLuint shader, char * key, const float* value){
	glUniformMatrix4fv(glGetUniformLocation(shader, key), 1, GL_FALSE,value);
}

