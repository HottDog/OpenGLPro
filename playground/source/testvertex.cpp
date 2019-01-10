#include"testvertex.h"
#include"common/shader.hpp"
#include"common/opengltool.h"
#include"playground/vertexdata.h"
bool TestVertex::Run() {
	GLFWwindow* window = CreateGLWindows(1024, 768, "test");

	//����shader
	GLuint shader = LoadShaders("shader/SimpleVertexShader.vertexshader", "shader/SimpleFragmentShader.fragmentshader");

	//����һ��VAO
	GLuint VAO = CreateVAO(1);

	//����һ��VBO
	GLuint VBO = CreateVBO(1);
	//��VBO��������
	VBOBindData(VBO, triangle_vertex_buffer_data, sizeof(triangle_vertex_buffer_data));

	//��VBO�󶨵�VAO
	VAOBindBuffer(VAO, VBO, 0);


}