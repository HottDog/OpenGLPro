#pragma once
#include"playground/RectTask.h"
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
};