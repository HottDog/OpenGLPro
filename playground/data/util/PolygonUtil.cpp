#include"PolygonUtil.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
bool IsConcavePolygon(Polygon& p)
{
	bool isFirstBig;
	for (int i = 0; i < p.pointCount; i++)
	{
		vec3 point1;
		vec3 point2;
		vec3 point3;
		if (i == p.pointCount - 1)
		{
			point1 = p.points[i];
			point2 = p.points[0];
			point3 = p.points[1];
		}
		else
		{
			point1 = p.points[i];
			point2 = p.points[i + 1];
			point3 = p.points[i + 2];
		}
		vec3 v1 = vec3(point2.x - point1.x, point2.y - point1.y,
			point2.z - point1.z);
		vec3 v2 = vec3(point3.x - point2.x, point3.y - point2.y,
			point3.z - point2.z);
		vec3 crossV = cross(v1,v2);
		if (i == 0)
		{
			if (crossV.z > 0)
			{
				isFirstBig = true;
			}
			else
			{
				isFirstBig = false;
			}
		}
		else
		{
			if ((isFirstBig&&crossV.z<0)|| (!isFirstBig && crossV.z > 0))
			{
				return true;
			}
		}
		
	}
	return false;
}