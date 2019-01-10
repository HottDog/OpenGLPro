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
//创建openGL的一个窗口
GLFWwindow* CreateGLWindows(int length,int width,char * title);

//创建一个VAO
GLuint CreateVAO(int index);

//创建一个VBO
GLuint CreateVBO(int index);

//VAO绑定VBO
void VAOBindBuffer(GLuint vao, GLuint vbo, int index);

//VBO传入数据
//size byte的大小，多少byte
void VBOBindData(GLuint vbo,const GLfloat* data,int size);

//获取当前的时间，单位是秒
double GetCurTime();

//获取上一帧的帧间隔时间,单位是秒
double GetDeltaTime();
//glfwGetTime();   获取当前程序运行的时间

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