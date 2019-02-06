#pragma once
#include"playground/RectTask.h"
#include"playground/shape/rect.h"
#include<vector>
#include"playground/util/DrawUtil.h"
using namespace std;
class RectPack:public RectTask {
public :
	RectPack();
protected:
	bool virtual Start();
	bool virtual Draw();
	bool virtual Destroy();

private:
	vector<Rect> rects;
};