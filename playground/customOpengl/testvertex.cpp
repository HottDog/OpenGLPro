#include"playground/customOpengl/testvertex.h"
#include"playground/vertexdata.h"
#include"common/shader.hpp"
bool TestVertex::Run() {
	//����һ�����ڶ���
	GLFWwindow* window;
	//��ʼ��glfw
	if (!glfwInit())
	{
		cout << "Failed to initialize GLFW" << endl;
		return false;
	}
	//����Opengl��һЩͼ������
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//����һ�����ڶ���
	window = glfwCreateWindow(1024, 768, "Playground1", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials." << endl;
		glfwTerminate();
		return false;
	}
	//�Ѵ����Ĵ��ڶ�������Ϊopengl�ĵ�ǰ������
	glfwMakeContextCurrent(window);
	//��ʼ��glew
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLEW" << endl;
		glfwTerminate();
		return false;
	}
	//�󶨰��������¼�
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	//����Ļ��ճ�ĳ����ɫ
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	//ʹ��shader
	GLuint programID = LoadShaders("customOpengl//NormalVertexShader.glsl", "customOpengl//NormalFragmentShader.glsl");
	//׼������
	//VAO
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//VBO Ҫ����GPU������
	//�����εĶ�������
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(regular_rectangle_vertex), regular_rectangle_vertex, GL_STATIC_DRAW);
	//�ڶ��������εĶ�������
	GLuint vertexbuffer1;
	glGenBuffers(1, &vertexbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(regular_hexagon_vertex), regular_hexagon_vertex, GL_STATIC_DRAW);
	//uv����ɫֵ����
	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(regular_hexagon_color), regular_hexagon_color, GL_STATIC_DRAW);
	//����ѭ��ȥˢ����Ļ�����1s����ˢ��30�Σ���ô����30֡
	do {
		//�����Ļ. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear(GL_COLOR_BUFFER_BIT);
		//ʹ��shader
		glUseProgram(programID);
		// ����ͼ��
		// VAO�󶨵ĵ�һ������
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		//����VBO�������ݵĽ�����ʽ
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		//ֱ����buffer�ڶ���˳�򱣴������
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);
		//����uv������ɫ����
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			2,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// ����������
		glDrawArrays(GL_TRIANGLES,0, 3 * 4); // 3*4 indices starting at 0 -> 4 triangle
											  //���VAO�����ݰ�
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &colorbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return true;
}