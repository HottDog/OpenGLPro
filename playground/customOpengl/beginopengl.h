#pragma once
#include"playground/itask.h"
#include<iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include"common/shader.hpp"
using namespace std;
//һ�����������εĶ��㣬����������
//����������ɫ��
//��������uv��ɫֵ
//�ġ�����MVP����任
class BeginOpengl :public ITask {
public :
	bool Run();
};