#include"playground/customOpengl/testvertex.h"
#include"playground/vertexdata.h"
#include"common/shader.hpp"
bool TestVertex::Run() {
	//创建一个窗口对象
	GLFWwindow* window;
	//初始化glfw
	if (!glfwInit())
	{
		cout << "Failed to initialize GLFW" << endl;
		return false;
	}
	//设置Opengl的一些图形属性
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//创建一个窗口对象
	window = glfwCreateWindow(1024, 768, "Playground1", NULL, NULL);
	if (window == NULL) {
		cout << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials." << endl;
		glfwTerminate();
		return false;
	}
	//把创建的窗口对象设置为opengl的当前上下文
	glfwMakeContextCurrent(window);
	//初始化glew
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		cout << "Failed to initialize GLEW" << endl;
		glfwTerminate();
		return false;
	}
	//绑定按键监听事件
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	//把屏幕清空成某种颜色
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	//使用shader
	GLuint programID = LoadShaders("customOpengl//NormalVertexShader.glsl", "customOpengl//NormalFragmentShader.glsl");
	//准备数据
	//VAO
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//VBO 要传给GPU的数据
	//三角形的顶点数据
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(regular_rectangle_vertex), regular_rectangle_vertex, GL_STATIC_DRAW);
	//第二组三角形的顶点数据
	GLuint vertexbuffer1;
	glGenBuffers(1, &vertexbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(regular_hexagon_vertex), regular_hexagon_vertex, GL_STATIC_DRAW);
	//uv的颜色值数据
	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(regular_hexagon_color), regular_hexagon_color, GL_STATIC_DRAW);
	//无限循环去刷新屏幕，如果1s内能刷新30次，那么就是30帧
	do {
		//清空屏幕. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear(GL_COLOR_BUFFER_BIT);
		//使用shader
		glUseProgram(programID);
		// 绘制图形
		// VAO绑定的第一个数据
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		//定义VBO缓存数据的解析格式
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		//直接拿buffer第二个顺序保存的数据
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
		//解析uv顶点颜色数据
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

		// 绘制三角形
		glDrawArrays(GL_TRIANGLES,0, 3 * 4); // 3*4 indices starting at 0 -> 4 triangle
											  //解除VAO的数据绑定
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