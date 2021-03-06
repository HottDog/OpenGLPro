#pragma once
#include"playground/system/normaltask.h"
#include"playground/data/view/rect.h"
class DrawSomePictures :public NormalTask {
public:
	DrawSomePictures();

protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();

private:
	GLuint shader;
	GLuint VAO;
	GLuint VBO;
	GLuint UV;
	GLuint EBO;
	GLuint texture;

	Rect rect1;
	Rect rect2;
	Rect rect3;
	Rect rect4;
};