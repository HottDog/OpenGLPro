#pragma once
#include"playground/data/point.h"
#include"common/globalconfig.h"
#include <math.h>
//获取点a和b的s等分点p的坐标，s = |ap|/|pb|
Point GetDividePoint(Point& a, Point& b, float s);

//平面坐标旋转计算公式：
//平面坐标上,点(x1,y1)绕点(x2,y2)旋转θ之后的坐标(x,y)
//x = (x1 - x2)*cos(θ) - (y1 - y2)*sin(θ) + x2;
//y = (x1 - x2)*sin(θ) + (y1 - y2)*cos(θ) + y2;
//获取点a绕点b顺时针旋转angle后的坐标
Point GetRotatePoint(Point&a, Point & b, float angle);