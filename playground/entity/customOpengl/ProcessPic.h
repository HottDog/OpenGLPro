#pragma once
#include"playground/system/RectTask.h"
#include"playground/data/view/rect.h"
class ProcessPic :public RectTask {
public:
	ProcessPic();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();
private:
	GLuint defaultShader;
	GLuint proShader;
	void DrawThreePic(Rect rect);
};