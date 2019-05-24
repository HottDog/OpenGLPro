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
#include"playground/entity/util/tool.h"
#include<string>
#include<vector>
#include"common/stb_image.h"
#include<map>
using namespace std;
using namespace glm;

struct RectOG {
	GLuint shader;
	GLuint vao;
	GLuint vertex;
	GLuint uv;
	GLuint index;
	GLuint texture;
	GLuint texture2;
	GLuint texture3;
};

struct Character{
	char value;
	GLuint textureID;   // 字形纹理的ID
	ivec2 size;			// 字形大小
	ivec2 Bearing;	    // 从基准线到字形左部/顶部的偏移值
	GLuint Advance;		// 原点距下一个字形原点的距离
};

//创建openGL的一个窗口
GLFWwindow* CreateGLWindows(int length,int width,char * title);

//创建一个VAO
GLuint CreateVAO(int index);

//创建一个VBO
GLuint CreateVBO(int index);

//创建一个EBO
GLuint CreateEBO(int index);

//创建一个纹理对象
GLuint CreateTexture(int index);

//VAO绑定VBO
void VAOBindBuffer(GLuint vao, GLuint vbo, int index,int size = 3);

//VBO传入数据
//size byte的大小，多少byte
void VBOBindData(GLuint vbo,const GLfloat* data,int size);

//EBO绑定数据
void EBOBindData(GLuint ebo, const unsigned int* data, int size);

//texture绑定数据
//@param
//texuture  纹理对象
//level  纹理指定多级渐远纹理的级别，如果你希望单独手动设置每个多级渐远纹理的级别的话。这里我们填0，也就是基本级别。
//width,height,data   图片数据
void TextureBindData(GLuint texture, int level, int width, int height, unsigned char * data);

//获取当前的时间，单位是秒
double GetCurTime();

//获取上一帧的帧间隔时间,单位是秒
double GetDeltaTime();
//glfwGetTime();   获取当前程序运行的时间

mat4 GetBaseMVP();

GLuint GetDefaultShaderWithoutSuffix(char * shadername);

map<GLchar, Character> LoadFont(char * fontpath = "res/Fonts/arial.ttf");

void InitRectOG(RectOG & rectOG);

void DeleteRectOG(RectOG & rectOG);

