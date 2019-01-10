#include"testvertex.h"
#include"common/shader.hpp"
#include"common/opengltool.h"
#include"playground/vertexdata.h"
bool TestVertex::Run() {
	GLFWwindow* window = CreateGLWindows(1024, 768, "test");

	//生成shader
	GLuint shader = LoadShaders("shader/SimpleVertexShader.vertexshader", "shader/SimpleFragmentShader.fragmentshader");

	//生成一个VAO
	GLuint VAO = CreateVAO(1);

	//生成一个VBO
	GLuint VBO = CreateVBO(1);
	//往VBO传入数据
	VBOBindData(VBO, triangle_vertex_buffer_data, sizeof(triangle_vertex_buffer_data));

	//把VBO绑定到VAO
	VAOBindBuffer(VAO, VBO, 0);


}