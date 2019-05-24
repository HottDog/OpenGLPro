#pragma once
#include"normaltask.h"
#include"common/opengltool.h"
class RectTask :public NormalTask {
public:
	RectTask();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();

	RectOG ogdata;

};