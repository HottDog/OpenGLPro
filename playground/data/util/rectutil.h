#pragma once
#include"playground/data/view/rect.h"
#include"mathutil.h"
#include"common/opengltool.h"
vector<Rect> SegaRect(Rect& r);

vector<Rect> SegaRects(vector<Rect>& rs);

//----Rect����ϵת����opengl����ϵ----
//ת����opengl��x����
float ToX(float posx);
//ת����opengl��y����
float ToY(float posy);

Point ToPos(Point & point);

Point2D ToUvPos(Point & point);

//----opengl����ϵת����Rect����ϵ----
//@param
// p opengl����ϵ��
Point ToRectPos(Point& p);

vec2 ToRectSize(vec2& size);

