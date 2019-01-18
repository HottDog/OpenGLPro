#pragma once
#include"playground/normaltask.h"
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
};