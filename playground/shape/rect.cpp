#include"rect.h"
int Rect::ID = 0;

Rect::Rect(){
	ID++;
	id = ID;
}

Rect::Rect(float x, float y, float w, float h) {
	ID++;
	id = ID;
	Rect::w = w;
	Rect::h = h;
	Rect::x = x;
	Rect::y = y;
}

vector<Triangle> Rect::Convert() {
	Process();
	vector<Triangle> triangles;
	Triangle t1;
	t1.x = ToPos(topLeft);
	t1.y = ToPos(bottomRight);
	t1.z = ToPos(topRight);
	Triangle t2;
	t2.x = ToPos(topLeft);
	t2.y = ToPos(bottomLeft);
	t2.z = ToPos(bottomRight);
	triangles.push_back(t1);
	triangles.push_back(t2);
	return triangles;
}

float Rect::ToX(float posx) {
	return (posx / WIDTH) * 2 - 1;
}

float Rect::ToY(float posy) {
	return 1 - ((posy / HEIGHT) * 2);
}

Point Rect::ToPos(Point & point) {
	Point t;
	t.x = ToX(point.x);
	t.y = ToY(point.y);
	return t;
}

void Rect::Process() {
	topLeft.x =x;
	topLeft.y = y;
	topLeft = GetRotatePoint(topLeft, topLeft, angle);

	topRight.x = x + w;
	topRight.y = y;
	topRight = GetRotatePoint(topRight, topLeft, angle);

	bottomRight.x = x + w;
	bottomRight.y = y + h;
	bottomRight = GetRotatePoint(bottomRight, topLeft, angle);

	bottomLeft.x = x;
	bottomLeft.y = y + h;
	bottomLeft = GetRotatePoint(bottomLeft, topLeft, angle);
}

//ƽ��������ת���㹫ʽ��
//ƽ��������,��(x1,y1)�Ƶ�(x2,y2)��ת��֮�������(x,y)
//x = (x1 - x2)*cos(��) - (y1 - y2)*sin(��) + x2;
//y = (x1 - x2)*sin(��) + (y1 - y2)*cos(��) + y2;
//(t.x,t.y)��(x,y)��ת
//Point Rect::Rotate(Point& t, float a) {
//	a = a / 180 * PI;
//	Point point;
//	point.x = (t.x - x)*cos(a) - (t.y-y)*sin(a) + x;
//	point.y = (t.x - x)*sin(a) + (t.y - y)*cos(a) + y;
//	return point;
//}