#pragma once
#include<vector>
#include"Line.h"
// Include GLM
#include <glm/glm.hpp>
using namespace glm;
//¼òµ¥¶à±ßÐÎ
class Polygon
{
public :
	Polygon(vec3 * points, int count);
	~Polygon();
	vector<Line> lines;
	int lineCount = 0;

	vector<Rect> GetRects();
	vec3 * points = nullptr;
	int pointCount;
};