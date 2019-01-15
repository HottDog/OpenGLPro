#include"playground/util/rectutil.h"
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