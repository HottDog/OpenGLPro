#include"DrawText.h"
#include"playground/entity/util/DrawUtil.h"
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
	font = Font(vec2(100, 100), 20, "This is my font!");
	font.Init(characters);

	content = Font(vec2(300, 300), 29, "Life is strange");
	content.Init(characters);

	fps = Font(vec2(0, 8), 8, "FPS:60");
	fps.Init(characters);
	return true;
}

bool DrawText::Draw() {
	NormalTask::Draw();
	DrawFont(font, VAO, VBO, UV, EBO, shader);
	DrawFont(content, VAO, VBO, UV, EBO, shader);
	DrawFont(fps, VAO, VBO, UV, EBO, shader);
	return true;
}

bool DrawText::Destroy() {
	NormalTask::Destroy();
	return true;
}