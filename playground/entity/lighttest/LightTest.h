#pragma once
#include"playground/system/normaltask.h"
#include"common/opengltool.h"
#include"playground/data/mesh/vertexs.h"
class LightTest :public NormalTask
{
public:
	LightTest();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();
private:
	RectOG ogObj;
	Mesh mesh;
};