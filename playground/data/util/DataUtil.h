#pragma once
#include"playground/data/mesh/vertexs.h"
#include"playground/data/mesh/point.h"
#include<vector>
#include"playground/data/view/rect.h"
using namespace std;
Vertexs TriangleToVertexs(vector<Triangle>& triangles);

template <typename T>
vector<T> Add(vector<vector<T>>& datas) {
	vector<T> result;
	for each (vector<T> var in datas)
	{
		for each (T temp in var)
		{
			result.push_back(temp);
		}
	}
	return result;
}

Vertexs RectsToVertexs(vector<Rect>& rects, bool isElement = false);

Vertexs RectsToVertexsWithoutElement(vector<Rect>& rects);

Vertexs RectsToVertexsWithElement(vector<Rect>& rects);

Vertexs RectToVertexs(Rect& rect, bool isElement = false);

Indexs RectsToIndexs(vector<Rect>& rects);

Vertexs PointsToVertexs(vector<Point>& points);

UVs PointsToUVs(vector<Point2D>& points);

UVs RectsToUVs(vector<Rect>& rects);

vec3 RandomColor();

Mesh MergeMesh(vector<Mesh> meshs);