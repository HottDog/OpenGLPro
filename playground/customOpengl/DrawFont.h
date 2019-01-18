#pragma once
#include"playground/normaltask.h"
#include"common/opengltool.h"
#include"playground/view/Font.h"
#include<map>
using namespace std;
class DrawFont :public NormalTask {
public:
	DrawFont();
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
	GLuint texture;
	map<GLchar, Character> characters;

	Font font;

	bool LoadFont();
	void DrawAChar();
};