#pragma once
#include"playground/itask.h"
#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include"common/shader.hpp"
using namespace std;
//一、给定三角形的顶点，绘制三角形
//二、加入着色器
//三、加入uv颜色值
//四、加入MVP顶点变换
class BeginOpengl :public ITask {
public :
	bool Run();
};