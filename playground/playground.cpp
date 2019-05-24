#include"playground/system/itask.h"
#include"playground/entity/customOpengl/opengltask.h"
#include<iostream>
#include"playground/entity/customOpengl/othertask.h"
#include"playground/entity/customOpengl/opengltask1.h"
#include"playground/entity/customOpengl//beginopengl.h"
#include"playground/entity/customOpengl/testvertex.h"
#include"playground/entity/customOpengl/testtask.h"
#include"playground/system/core/openglsystem.h"
#include"playground/system/draw/drawentity.h"
#include"playground/system/iopengltask.h"
#include"playground/entity/openglsystemtask.h"
using namespace OpenGL;
int main( void )
{
	// Initialise GLFW
	ITask *task;
	//task = new OpenglTask1();
	//task = new OtherTask();
	//task = new BeginOpengl();
	//task = new TestVertex();
	//task = new TestTask();
	task = new OpenglSystemTask();
	task->Run();
	delete(task);
	system("pause");
	//Application::GetInstance()->Register<DrawEntity>("1");
	//System::GetInstance()->Run();
	return 0;
}


