#pragma once
#include"playground/data/mesh/point.h"
#include"common/globalconfig.h"
//��ȡ��a��b��s�ȷֵ�p�����꣬s = |ap|/|pb|
Point GetDividePoint(Point& a, Point& b, float s);

//ƽ��������ת���㹫ʽ��
//ƽ��������,��(x1,y1)�Ƶ�(x2,y2)��ת��֮�������(x,y)
//x = (x1 - x2)*cos(��) - (y1 - y2)*sin(��) + x2;
//y = (x1 - x2)*sin(��) + (y1 - y2)*cos(��) + y2;
//��ȡ��a�Ƶ�b˳ʱ����תangle�������
Point GetRotatePoint(Point&a, Point & b, float angle);

//����a-b֮����������������a��b
int Random(int a, int b);

//����0-1֮��ĸ�����
double Random();

//�������
float Dot(Point p1, Point p2);

float Cross(Point p1, Point p2);