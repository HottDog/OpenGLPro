#pragma once
#include"playground/system/normaltask.h"
#include"playground/data/view/Font.h"
class DrawText :public NormalTask {
public:
	DrawText();

protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();
private:
	GLuint shader;
	GLuint lineShader;
	GLuint VAO;
	GLuint VBO;
	GLuint UV;
	GLuint EBO;
	map<GLchar, Character> characters;

	Font font;
	Font content;
	Font fps;
};