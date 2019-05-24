#include"RectPack.h"
#include"playground/data/util/DataUtil.h"
RectPack::RectPack() {

}

bool RectPack::Start() {
	RectTask::Start();

	ogdata.shader = GetDefaultShaderWithoutSuffix("DrawPicture");

	Rect rect(0,0, 100, 100);
	rect.color = RandomColor();
	rects.push_back(rect);

	Rect rect1(100, 0, 300, 150);
	rect1.color = RandomColor();
	rects.push_back(rect1);

	Rect rect2(0, 150, 300, 450);
	rect2.color = RandomColor();   
	rects.push_back(rect2);

	Rect rect3(300, 200, 100, 350);
	rect3.color = RandomColor();
	rects.push_back(rect3);

	Rect rect4(0, 600, 450, 100);
	rect4.color = RandomColor();
	rects.push_back(rect4);  

	Rect line(512, 0, 1, 768);
	rects.push_back(line);
	//Rect rect4()
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

void RectPack::_CreateRandomRect(int num,int width,int height) {
	for (int i = 0; i < num; i++) {

	}
}