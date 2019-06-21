#pragma once
#include"playground/data/view/rect.h"
#include <glm/glm.hpp>
#include<vector>
using namespace glm;
using namespace std;
struct Vec3MapRect
{
	vector<Rect> rects;
	vec3 color;
	Vec3MapRect(vec3 c);
};

bool HasColor(vector<Vec3MapRect>& datas, vec3 c);

Vec3MapRect* Find(vector<Vec3MapRect>& datas,vec3 c);

void InsertRect(vector<Vec3MapRect>& datas, vec3 c, Rect r);