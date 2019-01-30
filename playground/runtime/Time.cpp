#include"Time.h"
#include<GLFW/glfw3.h>
Time::Time() {

}

void Time::Start() {
	
}

void Time::Update() {
	double curtime = CurTime();
	lastFrameTime = curtime - lastTime;
	lastTime = curtime;
}

double Time::CurTime() {
	return glfwGetTime();
}

double Time::LastFrameTime() {
	return lastFrameTime;
}

Time* Time::_mInstance = nullptr;

void Time::Destroy() {
	delete _mInstance;
	_mInstance = nullptr;
}