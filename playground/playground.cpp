#include"itask.h"
#include"opengltask.h"
#include<iostream>
#include"othertask.h"
#include"opengltask1.h"
#include"customOpengl/beginopengl.h"
#include"playground/customOpengl/testvertex.h"
#include"testtask.h"
#include"playground/core/openglsystem.h"
#include"draw/drawentity.h"
#include"iopengltask.h"
#include"playground/openglsystemtask.h"
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


