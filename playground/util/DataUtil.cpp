#include"playground/util/DataUtil.h"
Vertexs TriangleToVertexs(vector<Triangle>& triangles) {
	Vertexs vertexs;
	int count = triangles.size() * 3 * 3;
	vertexs.datas = new float[count];
	vertexs.count = count;
	int i = 0;
	for each (Triangle var in triangles)
	{
		Point x = var.x;
		vertexs.datas[i] = x.x;
		vertexs.datas[i + 1] = x.y;
		vertexs.datas[i + 2] = x.z;
		Point y = var.y;
		vertexs.datas[i + 3] = y.x;
		vertexs.datas[i + 4] = y.y;
		vertexs.datas[i + 5] = y.z;
		Point z = var.z;
		vertexs.datas[i + 6] = z.x;
		vertexs.datas[i + 7] = z.y;
		vertexs.datas[i + 8] = z.z;
		i += 9;
	}
	return vertexs;
}

//rect-->>triangle-->vertexs
Vertexs RectsToVertexs(vector<Rect>& rects, bool isElement) {
	if (isElement) {
		return RectsToVertexsWithElement(rects);
	}
	else {
		return RectsToVertexsWithoutElement(rects);
	}
}

Vertexs RectsToVertexsWithoutElement(vector<Rect>& rects) {
	vector<vector<Triangle>> datas;
	for each (Rect var in rects)
	{
		datas.push_back(var.Convert());
	}
	Vertexs v = TriangleToVertexs(Add(datas));
	return v;
}

Vertexs RectsToVertexsWithElement(vector<Rect>& rects) {
	int count = rects.size() * 4 * 3;
	Vertexs v;
	v.datas = new float[count];
	v.count = count;
	int i = 0;
	for each (Rect var in rects)
	{
		Vertexs tempv = var.GetMesh().vertexs;
		for (int tempi = 0; tempi < 4 * 3; tempi++) {
			v.datas[i] = tempv.datas[tempi];
			i++;
		}
	}
	return v;
}

Vertexs RectToVertexs(Rect& rect, bool isElement) {
	if (isElement) {
		return rect.GetMesh().vertexs;
	}
	else {
		return TriangleToVertexs(rect.Convert());
	}

}

Indexs RectsToIndexs(vector<Rect>& rects) {
	Indexs indexs;
	int count = rects.size() * 6;
	indexs.datas = new unsigned int[count];
	indexs.count = count;
	int i = 0;
	for each (Rect var in rects)
	{
		Indexs temp = var.GetMesh().indexs;
		for (int tempi = 0; tempi < 6; tempi++) {
			indexs.datas[i] = temp.datas[tempi];
			i++;
		}
	}
	return indexs;
}

Vertexs PointsToVertexs(vector<Point>& points) {
	Vertexs vertexs;
	int count = points.size() * 3;
	vertexs.datas = new float[count];
	vertexs.count = count;
	int i = 0;
	for each (Point var in points)
	{
		vertexs.datas[i] = var.x;
		vertexs.datas[i + 1] = var.y;
		vertexs.datas[i + 2] = var.z;
		i += 3;
	}
	return vertexs;
}

UVs PointsToUVs(vector<Point2D>& points) {
	UVs uvs;
	int count = points.size() * 2;
	uvs.datas = new float[count];
	uvs.count = count;
	int i = 0;
	for each (Point2D var in points)
	{
		uvs.datas[i] = var.x;
		uvs.datas[i + 1] = var.y;
		i += 2;
	}
	return uvs;
}

UVs RectsToUVs(vector<Rect>& rects) {
	UVs uvs;
	int count = rects.size() * 4 * 2;
	uvs.datas = new float[count];
	uvs.count = count;
	int i = 0;
	for each (Rect var in rects)
	{
		UVs tempu = var.GetMesh().uvs;
		for (int tempi = 0; tempi < 4 * 2; tempi++) {
			uvs.datas[i] = tempu.datas[tempi];
			i++;
		}
	}
	return uvs;
}

