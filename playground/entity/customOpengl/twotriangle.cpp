#include"twotriangle.h"
#include"playground/data/util/DataUtil.h"

TwoTriangle::TwoTriangle() {
	name = "TwoTriangle";
}

bool TwoTriangle::Start() {
	NormalTask::Start();
	//创建shader
	//shader = LoadShaders("shader/SimpleVertexShader.vertexshader", "shader/SimpleFragmentShader.fragmentshader");
	shader = LoadShaders("shader/test.vertexshader", "shader/test.fragmentshader");
	//创建VAO
	VAO = CreateVAO(1);

	//创建ABO
	VBO = CreateVBO(1);
	VBO2 = CreateVBO(1);

	//逆时针
	static const GLfloat triangle_vertex1[] = {
		-1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		//1
		1.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,
		0.0f,-1.0f,0.0f,
	};
	static const GLfloat triangle_vertex2[] = {
		1.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,
		0.0f,-1.0f,0.0f,
	};
	//Rect rect1(100, 200, 100, 1);
	//rect1.angle = 45;
	//_AddRect(rect1);
	//Rect rect2(297, 400, 150, 1);
	//rect2.angle = 100;
	//_AddRect(rect2);
	Rect rect3(500, 50, 600, 1);
	rect3.angle = 100;
	_AddRect(rect3);
	for (int i = 0; i < 6; i++) {
		/*vector<vector<Rect>> rss;
		for each (Rect var in rects)
		{
			rss.push_back(SegaRect(var));
		}
		vector<Rect> result = Add(rss);*/
		vector<Rect> results = SegaRects(rects);
		_CleanRects();
		_AddRects(results);
	}
	//vector<Rect> rects;
	//rects.push_back(rect1);
	//rects.push_back(rect2);
	Vertexs v = RectsToVertexs(rects);
	//绑定VBO
	VBOBindData(VBO, v.datas, v.count*4);
	//VBOBindData(VBO, triangle_vertex2, sizeof(triangle_vertex2));
	
	return true;
}

bool TwoTriangle::Draw() {
	NormalTask::Draw();
	glUseProgram(shader);
	//开启VAO
	glEnableVertexAttribArray(0);
	//绑定VAO
	VAOBindBuffer(VAO,VBO, 0);
	//绘制三角形

	glDrawArrays(GL_TRIANGLES, 0, 3*rectNum*2);
	//关闭VAO
	glDisableVertexAttribArray(0);
	return true;
}

bool TwoTriangle::Destroy() {
	NormalTask::Destroy();
	return true;
}

void TwoTriangle::_AddRect(Rect& r) {
	rects.push_back(r);
	rectNum++;
}

void TwoTriangle::_AddRects(vector<Rect>& rs) {
	for each (Rect var in rs)
	{
		_AddRect(var);
	}
}

void TwoTriangle::_RemoveRect(Rect& r) {
	vector<Rect>::iterator it;
	for (it = rects.begin(); it != rects.end();) {
		if (((Rect)*it).id == r.id) {
			rects.erase(it);
			rectNum--;
			return;
		}
	}
	
}

void TwoTriangle::SegaAllRects() {
	vector<vector<Rect>> rss;
	for each (Rect var in rects)
	{
		rss.push_back(SegaRect(var));
	}
	vector<Rect> result = Add(rss);
	_AddRects(result);
}

void TwoTriangle::_CleanRects()
{
	/*vector<Rect>::iterator it;
	for (it = rects.begin(); it != rects.end();) {
		rects.erase(it);
	}*/
	vector<Rect>().swap(rects);
	rectNum = 0;
}