#pragma once
#include"playground/system/normaltask.h"
#include"common/opengltool.h"
#include"playground/data/view/Font.h"
#include<map>
using namespace std;
class DrawSomeFont :public NormalTask {
public:
	DrawSomeFont();
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