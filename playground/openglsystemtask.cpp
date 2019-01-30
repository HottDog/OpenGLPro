#include"openglsystemtask.h"
#include"iopengltask.h"
#include"common/opengltool.h"
#include"normaltask.h"
#include"runtime/Time.h"
#include"playground/customOpengl/twotriangle.h"
#include"playground/customOpengl/RectAddRect.h"
#include"playground/customOpengl/DrawPicture.h"
#include"playground/customOpengl/DrawSomePictures.h"
#include"playground/customOpengl/DrawFont.h"
#include"playground/customOpengl/DrawText.h"
#include"playground/customOpengl/ProcessPic.h"
#include"playground/customOpengl/TransformRect.h"
#include"playground/test/NormalTest.h"
#include<math.h>
#include <time.h>
#include"playground/customOpengl/RectPack.h"
bool OpenglSystemTask::Run() {
	IOpenglTask *task;
	//ÊµÀý»¯task
	//task = new NormalTask();
	//task = new TwoTriangle();
	//task = new RectAddRect();
	//task = new DrawPicture();
	//task = new DrawSomePictures();
	//task = new DrawFont();
	//task = new DrawText();
	//task = new ProcessPic();
	task = new RectPack();
	srand((unsigned)time(NULL));
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