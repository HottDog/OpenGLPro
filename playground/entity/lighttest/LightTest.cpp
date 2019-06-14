#include"LightTest.h"
#include"playground/entity/util/DrawUtil.h"
#include"playground/data/mesh/vertexdata.h"
LightTest::LightTest()
{

}

bool LightTest::Start()
{
	NormalTask::Start();
	InitRectOG(ogObj);
	ogObj.shader = GetDefaultShaderWithoutSuffix("uv_color");
	Vertexs v;
	return true;
}

bool LightTest::Draw()
{
	NormalTask::Draw();
	glUseProgram(ogObj.shader);
	

	return true;
}

bool LightTest::Destroy()
{
	NormalTask::Destroy();
	return true;
}