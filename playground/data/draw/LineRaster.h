#pragma once
#include <glm/glm.hpp>
#include"playground/data/config/Color.h"
using namespace glm;
class LineRaster
{
public:
	vec2* datas = nullptr;
	int length;
	vec2 start;
	vec2 end;
	Color color;
private:
	~LineRaster();
};