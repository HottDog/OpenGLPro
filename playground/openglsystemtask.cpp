#include"openglsystemtask.h"
#include"iopengltask.h"
#include"common/opengltool.h"
#include"normaltask.h"
#include"playground/customOpengl/twotriangle.h"
#include"playground/customOpengl/RectAddRect.h"
bool OpenglSystemTask::Run() {
	IOpenglTask *task;
	//ÊµÀı»¯task
	//task = new NormalTask();
	//task = new TwoTriangle();
	task = new RectAddRect();

	task->Start();

	do {
		task->Update();
	} while (task->IsEnd());

	task->Destroy();

	delete(task);

	return true;
}