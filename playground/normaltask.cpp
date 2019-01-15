#include"normaltask.h"
bool NormalTask::Start() {
	window = CreateGLWindows(width, height, name);
	
	return true;
}

bool NormalTask::Update() {
	if(isClearFrame)
		glClear(GL_COLOR_BUFFER_BIT);
	Draw();
	// Swap buffers,ÿ�ε�������ͱ�ʾˢ��һ֡
	if(isAutoRefreshFrame)
		glfwSwapBuffers(window);
	glfwPollEvents();
	return true;
}

bool NormalTask::Draw() {
	return true;
}

bool NormalTask::Destroy() {
	glfwTerminate();
	return true;
}

bool NormalTask::IsEnd() {
	return (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
}

NormalTask::NormalTask(char * n) 
{
	if(n!=nullptr)
		name = n;
}

NormalTask::NormalTask()
{

}

NormalTask::~NormalTask() {
	delete(name);
	if (window != nullptr) {
		delete(window);
	}
	
}
