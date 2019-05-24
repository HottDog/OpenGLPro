#include"playground/system/RectTask.h"

RectTask::RectTask() {

}

bool RectTask::Start() {
	NormalTask::Start();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	ogdata.vao = CreateVAO(1);
	ogdata.vertex = CreateVBO(1);
	ogdata.uv = CreateVBO(1);
	ogdata.index = CreateEBO(1);
	ogdata.texture = CreateTexture(1);
	return true;
}

bool RectTask::Draw() {
	NormalTask::Draw();

	return true;
}

bool RectTask::Destroy() {
	NormalTask::Destroy();
	DeleteRectOG(ogdata);
	return true;
}

