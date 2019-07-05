#pragma once
#include <glm/glm.hpp>
#include<GL/glew.h>
using namespace glm;

typedef unsigned char ubyte;

void CutOffLine(vec2 *&data, int& length,vec2 start,vec2 end,vec2 min,vec2 max);

ubyte Decode(vec2 point, vec2 min, vec2 max);