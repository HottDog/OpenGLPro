#include"TransformRect.h"
#include"playground/shape/rect.h"
#include"playground/util/DrawUtil.h"
TranformRect::TranformRect() {

}

bool TranformRect::Start() {
	RectTask::Start();

	ogdata.shader = GetDefaultShaderWithoutSuffix("Transform");

	
	return true;
}

bool TranformRect::Draw() {
	RectTask::Draw();

	//h += GetDeltaTime()*speed;
	
	tranform = translate(tranform, vec3(GetDeltaTime()*speed, 0, 0));

	GLuint matrix = glGetUniformLocation(ogdata.shader, "transform");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, &tranform[0][0]);

	Rect rect(50, 100, 450, 300);
	rect.image = "res/yasuo.jpg";
	DrawRect(rect,ogdata);
	return true;
}

bool TranformRect::Destroy() {
	RectTask::Destroy();
	return true;
}