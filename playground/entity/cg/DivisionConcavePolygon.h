#pragma once
#include"playground/system/RectTask.h"
#include"playground/data/view/Font.h"
class DivisionConcavePolygon :public RectTask
{
public:
	DivisionConcavePolygon();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();

private:
	GLuint fontShader;
	Font font;
};