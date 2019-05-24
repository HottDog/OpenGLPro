#include"DrawSomePictures.h"
#include"playground/entity/util/DrawUtil.h"
#include"playground/data/util/DataUtil.h"
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

	rect1= Rect(100, 100, 100, 100);
	rect1.image = "res/container.jpg";

	rect2= Rect(300, 100, 100, 100);
	rect2.image = "res/wushi.jpg";

	rect3= Rect(500, 100, 100, 100);
	rect3.image = "res/yasuo.jpg";
	rect3.color = RandomColor();

	rect4 = Rect(300, 300, 200, 200);
	rect4.color = RandomColor();
	return true;
}

bool DrawSomePictures::Draw() {
	
	DrawRect(rect1, VAO, VBO, UV, EBO, texture,shader);

	
	DrawRect(rect2, VAO, VBO, UV, EBO, texture, shader);

	
	
	DrawRect(rect3, VAO, VBO, UV, EBO, texture, shader);

	DrawRect(rect4, VAO, VBO, UV, EBO, texture, shader);
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

