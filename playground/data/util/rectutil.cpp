#include"rectutil.h"
#include"DataUtil.h"
vector<Rect> SegaRect(Rect& r) {
	r.Process();

	Rect r1(r.x, r.y, r.w / 3, r.h);
	r1.angle = r.angle;

	Point p2 = GetDividePoint(r.topLeft, r.topRight, 0.5f);
	Rect r2(p2.x, p2.y, r.w / 3, r.h);
	r2.angle = r.angle - 60;

	Point p3 = GetDividePoint(r.topLeft, r.topRight, 2.0f);
	Rect r3(p3.x, p3.y, r.w / 3, r.h);
	r3.angle = r.angle - 120;

	Rect r4(p3.x, p3.y, r.w / 3, r.h);
	r4.angle = r.angle;

	vector<Rect> rects;
	rects.push_back(r1);
	rects.push_back(r2);
	rects.push_back(r3);
	rects.push_back(r4);
	return rects;
}

vector<Rect> SegaRects(vector<Rect>& rs) {
	vector<vector<Rect>> rss;
	for each (Rect var in rs)
	{
		rss.push_back(SegaRect(var));
	}
	return Add(rss);
}

Point ToRectPos(Point& p) {
	Point result;
	result.x = (p.x + 1) / 2 * WIDTH;
	result.y = (1 - p.y) / 2 * HEIGHT;
	return result;
}

vec2 ToRectSize(vec2& size) {
	vec2 result;
	result.x = size.x*WIDTH;
	result.y = size.y*HEIGHT;
	return result;
}

float ToX(float posx) {
	return (posx / WIDTH) * 2 - 1;
}

float ToY(float posy) {
	return 1 - ((posy / HEIGHT) * 2);
}

Point ToPos(Point & point) {
	Point t;
	t.x = ToX(point.x);
	t.y = ToY(point.y);
	return t;
}

Point2D ToUvPos(Point & point) {
	Point2D t;
	t.x = point.x / WIDTH;
	t.y = 1 - point.y / HEIGHT;
	return t;
}