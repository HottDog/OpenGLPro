#include"Line.h"
#include <math.h>

Line::Line(float leftX, float leftY, float rightX, float rightY)
{
	rect = Rect();
	rect.x = leftX;
	rect.y = leftY;
	rect.w = sqrt((rightX - leftX)*(rightX - leftX) + (rightY - leftY)*(rightY - leftY));
	rect.h = 2;
	rect.angle = acos((rightX - leftX) / rect.w)/PI*180;
	if (rightY < leftY)
	{
		rect.angle = -rect.angle;
	}
	rect.color = vec3(1, 0, 0);
}

Rect Line::GetRect()
{
	return rect;
}

void Line::SetSize(float size)
{
	rect.h = size;
}