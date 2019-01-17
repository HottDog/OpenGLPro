#pragma once
#include"playground/normaltask.h"
#include"playground/view/Font.h"
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
};