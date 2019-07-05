#pragma once
#include"playground/system/normaltask.h"
#include"common/opengltool.h"
class RenderShadow : public NormalTask
{
public:
	RenderShadow();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();
private:
	RectOG ogObj;

	void LoadModel();
};