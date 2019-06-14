#include"point.h"
Point2D::Point2D(){}

Point2D::Point2D(float x, float y) {
	Point2D::x = x;
	Point2D::y = y;
}

Point::Point()
{

}

Point::Point(float x, float y, float z)
{
	Point::x = x;
	Point::y = y;
	Point::z = z;
}

Point Point::operator +(const Point& point)
{
	Point result;
	result.x = x + point.x;
	result.y = y + point.y;
	result.z = z + point.z;
	return result;
}

