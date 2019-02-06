#include"TransformRect.h"
#include"playground/shape/rect.h"
#include"playground/util/DrawUtil.h"
#include"playground/util/rectutil.h"
TranformRect::TranformRect() {

}

bool TranformRect::Start() {
	RectTask::Start();

	ogdata.shader = GetDefaultShaderWithoutSuffix("Transform");
	tranform = scale(tranform, vec3(0.8, 0.8, 1));
	
	return true;
}

bool TranformRect::Draw() {
	RectTask::Draw();
	
	Rect rect(50, 100, 450, 300);
	rect.image = "res/yasuo.jpg";
	rect.Process();
	//h += GetDeltaTime()*speed;
	
	//tranform = translate(tranform, vec3(GetDeltaTime()*speed, 0, 0));
	//Point p = ToPos(rect.topLeft);
	//tranform = rotate(tranform, 1.0f, vec3(p.x,p.y,1));
	

	GLuint matrix = glGetUniformLocation(ogdata.shader, "transform");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, &tranform[0][0]);

	
	DrawRect(rect,ogdata);
	return true;
}

bool TranformRect::Destroy() {
	RectTask::Destroy();
	return true;
}