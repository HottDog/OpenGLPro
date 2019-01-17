#include"DrawText.h"
#include"playground/util/DrawUtil.h"
DrawText::DrawText(){}

bool DrawText::Start() {
	NormalTask::Start();

	characters = LoadFont();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	shader = GetDefaultShaderWithoutSuffix("Font");
	lineShader = GetDefaultShaderWithoutSuffix("test");
	//glUseProgram(shader);
	VAO = CreateVAO(1);
	VBO = CreateVBO(1);
	UV = CreateVBO(1);
	EBO = CreateEBO(1);

	//准备font数据
	font = Font(vec2(100, 100), 50, "this is my font");
	font.Init(characters);
	return true;
}

bool DrawText::Draw() {
	NormalTask::Draw();
	for each (Font::FontItem var in font.childs)
	{
		DrawFontItem(var, font.color, VAO, VBO, UV, EBO, shader);
	}
	return true;
}

bool DrawText::Destroy() {
	NormalTask::Destroy();
	return true;
}