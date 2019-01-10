#pragma once
#include"iopengltask.h"
#include"common/opengltool.h"
//opengl绘制一个常见窗口
//窗口大小：1024*768
class NormalTask :public IOpenglTask {
public:
	char * name = "NormalTask";  
	GLFWwindow* window = nullptr;
	int width = WIDTH;
	int height = HEIGHT;
	bool isClearFrame = true;
	NormalTask(char * n );
	NormalTask();
	virtual ~NormalTask();

protected:
	virtual bool Start();
	virtual bool Update();
	virtual bool Draw();
	virtual bool Destroy();
	virtual bool IsEnd();
};