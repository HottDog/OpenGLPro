#pragma once
#include"playground/data/mesh/point.h"
#include"common/globalconfig.h"
//获取点a和b的s等分点p的坐标，s = |ap|/|pb|
Point GetDividePoint(Point& a, Point& b, float s);

//平面坐标旋转计算公式：
//平面坐标上,点(x1,y1)绕点(x2,y2)旋转θ之后的坐标(x,y)
//x = (x1 - x2)*cos(θ) - (y1 - y2)*sin(θ) + x2;
//y = (x1 - x2)*sin(θ) + (y1 - y2)*cos(θ) + y2;
//获取点a绕点b顺时针旋转angle后的坐标
Point GetRotatePoint(Point&a, Point & b, float angle);

//返回a-b之间的随机整数，包含a和b
int Random(int a, int b);

//返回0-1之间的浮点数
double Random();

//向量点乘
float Dot(Point p1, Point p2);

float Cross(Point p1, Point p2);