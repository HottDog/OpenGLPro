#pragma once
#include"playground/itask.h"
#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include"common/shader.hpp"
using namespace std;
class TestVertex :public ITask {
public:
	bool Run();
};