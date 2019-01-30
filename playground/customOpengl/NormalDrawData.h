#pragma once
#include<vector>
#include"playground/shape/rect.h"
#include"common/opengltool.h"
#include"playground/data/vertexs.h"
#include"playground/util/DataUtil.h"
using namespace std;
struct NormalDrawData {
public :
	vector<Rect> rects;
	int rectCount = 0;
	void AddRects(vector<Rect>& rects);
	void AddRect(Rect& rect);
	void RemoveRect(Rect& rect);
	void CleanRects();
	Vertexs ToVertexs(bool isElement = false);
	Indexs ToIndexs();
	UVs ToUVs();
};