#pragma once
#include"playground/system/RectTask.h"
#include"playground/data/view/rect.h"
#include<vector>
#include"playground/entity/util/DrawUtil.h"
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

	//���ɴ�С����Ķ������
	void _CreateRandomRect(int num, int width, int height);
};