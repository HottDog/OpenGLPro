#include"playground/customOpengl/DrawSomePictures.h"
#include"playground/util/DrawUtil.h"
DrawSomePictures::DrawSomePictures() {

}

bool DrawSomePictures::Start() {
	NormalTask::Start();

	shader = GetDefaultShaderWithoutSuffix("DrawPicture");
	glUseProgram(shader);
	VAO = CreateVAO(1);
	VBO = CreateVBO(1);
	UV = CreateVBO(1);
	EBO = CreateEBO(1);
	texture = CreateTexture(1);

	return true;
}

bool DrawSomePictures::Draw() {
	Rect rect1(100, 100, 100, 100);
	rect1.image = "res/container.jpg";
	DrawRect(rect1, VAO, VBO, UV, EBO, texture);

	Rect rect2(300, 100, 100, 100);
	rect2.image = "res/wushi.jpg";
	DrawRect(rect2, VAO, VBO, UV, EBO, texture);

	Rect rect3(500, 100, 100, 100);
	rect3.image = "res/yasuo.jpg";
	DrawRect(rect3, VAO, VBO, UV, EBO, texture);
	return true;
}

bool DrawSomePictures::Destroy() {
	NormalTask::Destroy();

	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &UV);
	glDeleteProgram(shader);
	glDeleteVertexArrays(1, &VAO);

	glDeleteBuffers(1, &EBO);
	return true;
}

