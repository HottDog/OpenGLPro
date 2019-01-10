#include"playground/util/mathutil.h"
Point GetDividePoint(Point& a, Point& b, float s) {
	Point result;
	result.x = (a.x + s * b.x) / (1 + s);
	result.y = (a.y + s * b.y) / (1 + s);
	return result;
}

Point GetRotatePoint(Point&a, Point & b, float angle) {
	angle = angle / 180 * PI;
	Point point;
	point.x = (a.x - b.x)*cos(angle) - (a.y - b.y)*sin(angle) + b.x;
	point.y = (a.x - b.x)*sin(angle) + (a.y - b.y)*cos(angle) + b.y;
	return point;
}