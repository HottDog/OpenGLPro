#pragma once
#include"playground/system/normaltask.h"
#include"common/opengltool.h"
#include"playground/data/view/rect.h"
#include"playground/data/mesh/NormalDrawData.h"
class RectAddRect :public NormalTask {
public:
	RectAddRect();

protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();
private:
	void _DrawFrame();

	GLuint shader;
	GLuint VAO;
	GLuint VBO;
	NormalDrawData drawData;
	double runTime = 0.0;
	int x = 100;
};