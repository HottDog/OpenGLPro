#pragma once
#include"playground/system/itask.h"
#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include"common/shader.hpp"
using namespace std;
class TestVertex1 :public ITask {
public:
	bool Run();
};