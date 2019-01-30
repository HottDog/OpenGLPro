#pragma once
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
void SetShaderData(GLuint shader, char * key, const float value);

void SetShaderData(GLuint shader, char * key, const vec2 value);

void SetShaderData(GLuint shader, char * key,const vec3 value);

void SetShaderData(GLuint shader, char * key, const float* value);