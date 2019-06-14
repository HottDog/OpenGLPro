#include"rect.h"
#include"playground/data/util/DataUtil.h"
#include"playground/data/util/rectutil.h"
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

Mesh Rect::GetMesh() {
	Process();
	vector<Point> points;
	points.push_back(ToPos(topLeft));
	points.push_back(ToPos(topRight));
	points.push_back(ToPos(bottomRight));
	points.push_back(ToPos(bottomLeft));
	Mesh mesh;
	mesh.vertexs = PointsToVertexs(points);
	mesh.indexs = CreateIndexs();
	mesh.uvs = GetUVs();
	return mesh;
}



Indexs Rect::CreateIndexs() {
	Indexs indexs;
	indexs.count = 6;
	indexs.datas = new unsigned int[indexs.count]{
		0,2,1,
		0,3,2
	};
	return indexs;
}

UVs Rect::GetUVs() {
	if (texFillType == Fill) {
		return GetFillUVs();
	}
	else {
		return GetRelaUVs();
	}
}

UVs Rect::GetFillUVs() {
	vector<Point2D> points;
	points.push_back(Point2D(0, 1));
	points.push_back(Point2D(1, 1));
	points.push_back(Point2D(1, 0));
	points.push_back(Point2D(0, 0));
	return PointsToUVs(points);
}

UVs Rect::GetRelaUVs() {
	vector<Point2D> points;
	points.push_back(ToUvPos(topLeft));
	points.push_back(ToUvPos(topRight));
	points.push_back(ToUvPos(bottomRight));
	points.push_back(ToUvPos(bottomLeft));
	return PointsToUVs(points);
}

void Rect::Rotate()
{
	topLeft = GetRotatePoint(topLeft, topLeft, angle);
	topRight = GetRotatePoint(topRight, topLeft, angle);
	bottomRight = GetRotatePoint(bottomRight, topLeft, angle);
	bottomLeft = GetRotatePoint(bottomLeft, topLeft, angle);
}

void Rect::Process() {
	topLeft.x =x;
	topLeft.y = y;
	
	topRight.x = x + w;
	topRight.y = y;
	
	bottomRight.x = x + w;
	bottomRight.y = y + h;
	
	bottomLeft.x = x;
	bottomLeft.y = y + h;	
	Rotate();
}

//平面坐标旋转计算公式：
//平面坐标上,点(x1,y1)绕点(x2,y2)旋转θ之后的坐标(x,y)
//x = (x1 - x2)*cos(θ) - (y1 - y2)*sin(θ) + x2;
//y = (x1 - x2)*sin(θ) + (y1 - y2)*cos(θ) + y2;
//(t.x,t.y)绕(x,y)旋转
//Point Rect::Rotate(Point& t, float a) {
//	a = a / 180 * PI;
//	Point point;
//	point.x = (t.x - x)*cos(a) - (t.y-y)*sin(a) + x;
//	point.y = (t.x - x)*sin(a) + (t.y - y)*cos(a) + y;
//	return point;
//}