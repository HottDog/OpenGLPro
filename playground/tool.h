#pragma once
#include<glm/glm.hpp>
#include <GL/glew.h>
using namespace glm;
void PrintVec4(vec4 c);
void PrintMat4(mat4 m);
GLuint loadBMP(const char * imagepath);