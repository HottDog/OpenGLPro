#include"testtask.h"
#include <GL/glew.h>

#include<iostream>
#include"common/opengltool.h"
#include"common/shader.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include"tool.h"
//#include"playground/vertexdata.h"
using namespace std;

const double speed = 0.2;

void Test1() {
	GLint *compressed_format;
	GLint num_compressed_format = 0;
	glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB, &num_compressed_format);
	compressed_format = new GLint[num_compressed_format];
	glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS_ARB, compressed_format);
	for (int i = 0; i < num_compressed_format; i++) {
		cout << compressed_format[i] << " ";
	}
}

bool TestTask::Run() {
	//Test1();
	GLFWwindow* window = CreateGLWindows(1024, 768,"test");
	// Enable depth test
	//glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	//glDepthFunc(GL_GREATER);
	//����shader
	GLuint shader = LoadShaders("shader/SimpleVertexShader.vertexshader", "shader/SimpleFragmentShader.fragmentshader");

	// ��ȡ��shader�еĲ�����MVP��������
	GLuint MatrixID = glGetUniformLocation(shader, "MVP");

	glm::mat4 MVP = GetBaseMVP(); // Remember, matrix multiplication is the other way around
	PrintMat4(MVP);
	//����һ��VAO
	GLuint VertexArrayID = CreateVAO(1);
	glBindVertexArray(VertexArrayID);
	//����һ��VBO
	GLuint vertexbuffer = CreateVBO(1);
	/*static GLfloat triangle_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};*/
	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};
	//��VBO��������
	//cout << "triangle_vertex_buffer_data������:" << sizeof(triangle_vertex_buffer_data) << endl;
	VBOBindData(vertexbuffer, g_vertex_buffer_data, sizeof(g_vertex_buffer_data));
	VAOBindBuffer(VertexArrayID,vertexbuffer, 0);
	bool isLeft = false;
	do {
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear(GL_COLOR_BUFFER_BIT);

		// Draw
		// Use our shader
		glUseProgram(shader);

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		
		//VAO����֮��Ĭ���ǹرյģ�ÿ�ΰ�VBO��Ҫ���¿���
		//����VAO
		glEnableVertexAttribArray(0);
		
		/*if (isLeft&&triangle_vertex_buffer_data[6] < -1) {
			isLeft = false;			
		}
		else if(!isLeft&&triangle_vertex_buffer_data[6] > 1) {
			isLeft = true;
		}

		if (isLeft) {
			triangle_vertex_buffer_data[6] -=(GLfloat)( GetDeltaTime() * speed);
		}
		else {
			triangle_vertex_buffer_data[6] += (GLfloat)(GetDeltaTime() * speed);
		}*/
		//cout << "�䶯������:" << triangle_vertex_buffer_data[6] << endl;
		//VBOBindData(vertexbuffer, triangle_vertex_buffer_data,sizeof(triangle_vertex_buffer_data));
		//VAOBindBuffer(VertexArrayID, vertexbuffer, 0);
		//VAO��Ҫʹ�õ�VBO����
		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		
		//glBindVertexArray(VertexArrayID);
		//����������
		glDrawArrays(GL_TRIANGLES, 0, 12* 3); // 3 indices starting at 0 -> 1 triangle

		//�ر�VAO
		glDisableVertexAttribArray(0);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return true;
}
