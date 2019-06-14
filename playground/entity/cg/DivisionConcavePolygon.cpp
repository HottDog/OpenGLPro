#include"DivisionConcavePolygon.h"
#include"playground/data/view/rect.h"
#include"playground/entity/util/DrawUtil.h"
#include"playground/data/view/Line.h"
#include"playground/data/view/Polygon.h"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include"playground/entity/runtime/RunTime.h"
#include"playground/data/util/PolygonUtil.h"
using namespace glm;
DivisionConcavePolygon::DivisionConcavePolygon()
{

}

bool DivisionConcavePolygon::Start()
{
	RectTask::Start();

	return true;
}

bool DivisionConcavePolygon::Draw()
{
	RectTask::Draw();
	Rect rect(50, 100, 450, 1);
	rect.color = vec3(1.0f, 0.0f, 0.0f);
	//DrawRect(rect, ogdata);
	
	Line line(300, 400, 400, 200);
	//DrawRect(line.GetRect(), ogdata);

	vec3 * points = new vec3 [5] ;
	points[0] = vec3(100, 200, 0);
	points[1] = vec3(300, 400, 0);
	points[2] = vec3(600, 400, 0);
	points[3] = vec3(400, 200, 0);
	points[4] = vec3(300, 300, 0);
	Polygon polygon(points, 5);
	for (int i = 0; i < polygon.lineCount; i++)
	{
		DrawRect(polygon.GetRects()[i], ogdata);
	}
	if (IsConcavePolygon(polygon))
	{
		font = Font(vec2(100, 100), 20, "is Concave Polygon");
	}
	else
	{
		font = Font(vec2(100, 100), 20, "isn't Concave Polygon");
	}
	
	DrawFont(font, ogdata);
	return true;
}

bool DivisionConcavePolygon::Destroy()
{
	RectTask::Destroy();
	return true;
}