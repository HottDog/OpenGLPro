#pragma once
#include"playground/RectTask.h"
class TranformRect :public RectTask {
public:
	TranformRect();
protected:
	bool virtual Start();
	bool virtual Draw();
	bool virtual Destroy();

private:
	mat4 tranform = mat4(1.0f);
	double speed = 20.0 / HEIGHT;
	double h = 0;
};