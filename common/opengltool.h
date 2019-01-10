#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<iostream>
#include"common/shader.hpp"
#include"common/globalconfig.h"
#include"playground/data/vertexs.h"
#include"playground/shape/rect.h"
#include"playground/tool.h"
using namespace std;
using namespace glm;
//����openGL��һ������
GLFWwindow* CreateGLWindows(int length,int width,char * title);

//����һ��VAO
GLuint CreateVAO(int index);

//����һ��VBO
GLuint CreateVBO(int index);

//VAO��VBO
void VAOBindBuffer(GLuint vao, GLuint vbo, int index);

//VBO��������
//size byte�Ĵ�С������byte
void VBOBindData(GLuint vbo,const GLfloat* data,int size);

//��ȡ��ǰ��ʱ�䣬��λ����
double GetCurTime();

//��ȡ��һ֡��֡���ʱ��,��λ����
double GetDeltaTime();
//glfwGetTime();   ��ȡ��ǰ�������е�ʱ��

mat4 GetBaseMVP();

Vertexs TriangleToVertexs(vector<Triangle>& triangles);

template <typename T>
vector<T> Add(vector<vector<T>>& datas) {
	vector<T> result;
	for each (vector<T> var in datas)
	{
		for each (T temp in var)
		{
			result.push_back(temp);
		}
	}
	return result;
}

Vertexs RectToVertexs(vector<Rect>& rects);

Vertexs RectToVertexs(Rect rect);