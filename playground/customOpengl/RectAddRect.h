#pragma once
#include"playground/normaltask.h"
#include"common/opengltool.h"
#include"playground/shape/rect.h"
#include"playground/customOpengl/NormalDrawData.h"
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