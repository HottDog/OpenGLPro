#include"TransformRect.h"
#include"playground/data/view/rect.h"
#include"playground/entity/util/DrawUtil.h"
#include"playground/data/util/rectutil.h"
TranformRect::TranformRect() {

}

bool TranformRect::Start() {
	RectTask::Start();

	ogdata.shader = GetDefaultShaderWithoutSuffix("Transform");

	tranform = rotate(tranform, radians(-90.0f), vec3(0, 0, 1));
	//tranform = scale(tranform, vec3(1.5, 1.5, 1.5));
	model = rotate(model, radians(-65.0f), vec3(1.0f, 0.0f, 0.0f));            
	view = translate(view, vec3(0.3f, -0.1f, -0.3f));
	projection = perspective(radians(45.0f), (float)WIDTH / HEIGHT, 0.1f, 100.0f);
	tranform = projection * view*model;
	return true;
}

bool TranformRect::Draw() {
	RectTask::Draw();
	Rect rect(50, 100, 450, 300);
	rect.image = "res/yasuo.jpg";
	//h += GetDeltaTime()*speed;
	//rect.Process();
	//Point center = rect.topLeft;
	//center.x += rect.w/2;
	//center.y += rect.h/2;
	//Point _center = ToPos(center);

	//tranform = translate(tranform, vec3(GetDeltaTime()*speed, 0, 0));
	//tranform = scale(tranform, vec3(0.5, 0.5, 0.5));
	
	GLuint matrix = glGetUniformLocation(ogdata.shader, "transform");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, &tranform[0][0]);

	
	DrawRect(rect,ogdata);
	return true;
}

bool TranformRect::Destroy() {
	RectTask::Destroy();
	return true;
}