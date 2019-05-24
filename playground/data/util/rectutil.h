#pragma once
#include"playground/data/view/rect.h"
#include"mathutil.h"
#include"common/opengltool.h"
vector<Rect> SegaRect(Rect& r);

vector<Rect> SegaRects(vector<Rect>& rs);

//----Rect坐标系转化成opengl坐标系----
//转化成opengl的x坐标
float ToX(float posx);
//转化成opengl的y坐标
float ToY(float posy);

Point ToPos(Point & point);

Point2D ToUvPos(Point & point);

//----opengl坐标系转化成Rect坐标系----
//@param
// p opengl坐标系点
Point ToRectPos(Point& p);

vec2 ToRectSize(vec2& size);

