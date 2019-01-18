#include"ProcessPic.h"
#include"playground/util/DrawUtil.h"
ProcessPic::ProcessPic() {

}

bool ProcessPic::Start() {
	RectTask::Start();
	proShader = GetDefaultShaderWithoutSuffix("picProcess/Pencil");
	defaultShader = GetDefaultShaderWithoutSuffix("DrawPicture");
	ogdata.shader = proShader;
	glUseProgram(ogdata.shader);
	return true;
}

bool ProcessPic::Draw() {
	RectTask::Draw();   
	Rect rect(50, 100, 450, 300);
	rect.image = "res/yasuo.jpg";
	ogdata.shader = defaultShader;
	DrawRect(rect, ogdata);

	Rect rect1(530, 100, 450, 300);
	rect1.image = "res/yasuo.jpg";
	ogdata.shader = proShader;
	DrawRect(rect1, ogdata);
	return true;
}

bool ProcessPic::Destroy() {
	RectTask::Destroy();
	return true;
}