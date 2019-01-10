#include"playground/customOpengl/NormalDrawData.h"
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

Vertexs NormalDrawData::ToVertexs() {
	Vertexs v;
	if (rectCount == 0) {
		return v;
	}
	else {
		return RectToVertexs(rects);
	}
}