#include"RectPack.h"

RectPack::RectPack() {

}

bool RectPack::Start() {
	RectTask::Start();

	ogdata.shader = GetDefaultShaderWithoutSuffix("DrawPicture");

	Rect rect(100, 100, 100, 100);
	rect.color = rect.RandomColor();
	rects.push_back(rect);

	return true;
}

bool RectPack::Draw() {
	RectTask::Draw();
	for each (Rect var in rects)
	{
		DrawRect(var, ogdata);
	}
	return true;
}        

bool RectPack::Destroy() {
	RectTask::Destroy();
	return true;
}