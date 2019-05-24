#include"NormalDrawData.h"
void NormalDrawData::AddRects(vector<Rect>& re) {
	for each (Rect var in re)
	{
		AddRect(var);
	}
}

void NormalDrawData::AddRect(Rect& re) {
	rects.push_back(re);
	rectCount++;
}

void NormalDrawData::RemoveRect(Rect& re) {
	vector<Rect>::iterator it;
	for (it = rects.begin(); it != rects.end();) {
		if (((Rect)*it).id == re.id) {
			rects.erase(it);
			rectCount--;
			return;
		}
	}
}

void NormalDrawData::CleanRects() {
	vector<Rect>().swap(rects);
	rectCount = 0;
}

Vertexs NormalDrawData::ToVertexs(bool isElement) {
	Vertexs v;
	if (rectCount == 0) {
		return v;
	}
	else {
		if (isElement) {
			return RectsToVertexs(rects, isElement);
		}
		else {
			return RectsToVertexs(rects);
		}
		
	}
}

Indexs NormalDrawData::ToIndexs() {
	return RectsToIndexs(rects);
}

UVs NormalDrawData::ToUVs() {
	return RectsToUVs(rects);
}