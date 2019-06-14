#include"Polygon.h"
Polygon::Polygon(vec3 * points,int count)
{
	Polygon::points = points;
	Polygon::pointCount = count;
	for (int i = 0; i < count; i++)
	{
		if ((i+1) >= count)
		{
			lines.push_back(Line(points[i].x, points[i].y, points[0].x, points[0].y));
		}
		else
		{
			lines.push_back(Line(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y));
		}
		
		lineCount++;
	}

}

Polygon::~Polygon()
{
	if (points != nullptr)
	{
		delete points;
		points = nullptr;
	}
}

vector<Rect> Polygon::GetRects()
{
	vector<Rect> result;
	for (int i = 0; i < lineCount; i++)
	{
		result.push_back(lines[i].GetRect());
	}
	return result;
}