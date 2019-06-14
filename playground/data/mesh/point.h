#pragma once
struct Point2D
{
	float x = 0;
	float y = 0;
	Point2D();
	Point2D(float x, float y);
};

struct Point
{
	float x = 0;
	float y = 0;
	float z = 0;
	Point();
	Point(float x, float y, float z);
	Point operator +(const Point& point);
};