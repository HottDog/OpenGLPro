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
	GLuint textureID;   // ���������ID
	ivec2 size;			// ���δ�С
	ivec2 Bearing;	    // �ӻ�׼�ߵ�������/������ƫ��ֵ
	GLuint Advance;		// ԭ�����һ������ԭ��ľ���
};

//����openGL��һ������
GLFWwindow* CreateGLWindows(int length,int width,char * title);

//����һ��VAO
GLuint CreateVAO(int index);

//����һ��VBO
GLuint CreateVBO(int index);

//����һ��EBO
GLuint CreateEBO(int index);

//����һ���������
GLuint CreateTexture(int index);

//VAO��VBO
void VAOBindBuffer(GLuint vao, GLuint vbo, int index,int size = 3);

//VBO��������
//size byte�Ĵ�С������byte
void VBOBindData(GLuint vbo,const GLfloat* data,int size);

//EBO������
void EBOBindData(GLuint ebo, const unsigned int* data, int size);

//texture������
//@param
//texuture  �������
//level  ����ָ���༶��Զ����ļ��������ϣ�������ֶ�����ÿ���༶��Զ����ļ���Ļ�������������0��Ҳ���ǻ�������
//width,height,data   ͼƬ����
void TextureBindData(GLuint texture, int level, int width, int height, unsigned char * data);

//��ȡ��ǰ��ʱ�䣬��λ����
double GetCurTime();

//��ȡ��һ֡��֡���ʱ��,��λ����
double GetDeltaTime();
//glfwGetTime();   ��ȡ��ǰ�������е�ʱ��

mat4 GetBaseMVP();

GLuint GetDefaultShaderWithoutSuffix(char * shadername);

map<GLchar, Character> LoadFont(char * fontpath = "res/Fonts/arial.ttf");

void InitRectOG(RectOG & rectOG);

void DeleteRectOG(RectOG & rectOG);

