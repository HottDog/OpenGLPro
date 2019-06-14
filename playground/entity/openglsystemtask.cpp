#include"openglsystemtask.h"
#include"playground/system/iopengltask.h"
#include"common/opengltool.h"
#include"playground/system/normaltask.h"
#include"runtime/Time.h"
#include"playground/entity/customOpengl/twotriangle.h"
#include"playground/entity/customOpengl/RectAddRect.h"
#include"playground/entity/customOpengl/DrawPicture.h"
#include"playground/entity/customOpengl/DrawSomePictures.h"
#include"playground/entity/customOpengl/DrawFont.h"
#include"playground/entity/customOpengl/DrawText.h"
#include"playground/entity/customOpengl/ProcessPic.h"
#include"playground/entity/customOpengl/TransformRect.h"
#include"playground/system/test/NormalTest.h"
#include<math.h>
#include <time.h>
#include"playground/entity/customOpengl/RectPack.h"
#include"playground/entity/cg/DivisionConcavePolygon.h"
#include"playground/entity/runtime/RunTime.h"
#include"playground/entity/cg/DrawChessBoard.h"
bool OpenglSystemTask::Run() {
	IOpenglTask *task;
	//ÊµÀý»¯task
	//task = new NormalTask();
	//task = new TwoTriangle();
	//task = new RectAddRect();
	//task = new DrawPicture();
	//task = new DrawSomePictures();
	//task = new DrawSomeFont();
	//task = new DrawText();
	//task = new ProcessPic();
	//task = new DivisionConcavePolygon();
	task = new DrawChessBoard();
	//task = new RectPack();
	Init();
	//task = new TranformRect();
	task->Start();
	NormalTest test;
	test.Start();
	do {
		srand((unsigned)time(NULL));
		Time::Instance()->Update();
		task->Update();
		test.Update();
	} while (task->IsEnd());

	task->Destroy();
	test.Destroy();
	delete(task);

	return true;
}

bool OpenglSystemTask::Init()
{
	srand((unsigned)time(NULL));
	RunTime::fontRes.insert(pair<string, map<GLchar, Character>>("arial", LoadFont()));
	return true;
}