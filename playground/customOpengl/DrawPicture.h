#pragma once
#include"playground/normaltask.h"
#include"playground/customOpengl/NormalDrawData.h"
#include"common/opengltool.h"
class DrawPicture :public NormalTask {
public:
	DrawPicture();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();

private:
	NormalDrawData drawData;
	GLuint shader;
	GLuint VAO;
	GLuint VBO;
	GLuint UV;
	GLuint EBO;
	GLuint texture;
};