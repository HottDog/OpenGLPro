#include"opengltool.h"
GLFWwindow * CreateGLWindows(int width, int height, char * title)
{
	// 初始化 GLFW
	if (!glfwInit()) {
		fprintf(stderr, "初始化GLFW失败\n");
		getchar();
		return nullptr;
	}
	
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	// Open a window and create its OpenGL context,default size:1024*768
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);
	
	// 初始化 GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "初始化GLEW失败\n");
		getchar();
		glfwTerminate();
		return nullptr;
	}
	GLenum ss = glGetError();
	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	return window;
}

//创建一个VAO
GLuint CreateVAO(int index) {
	GLuint VertexArrayID;
	glGenVertexArrays(index, &VertexArrayID);
	//glBindVertexArray(VertexArrayID);
	cout << "VAO(ID):" << VertexArrayID << endl;
	return VertexArrayID;
}

//创建一个VBO
GLuint CreateVBO(int index) {
	GLuint vertexbuffer;
	glGenBuffers(index, &vertexbuffer);	
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	cout << "VBO(id):" << vertexbuffer<<endl;
	return vertexbuffer;
}

void VBOBindData(GLuint vbo,const GLfloat* data,int size)
{	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VAOBindBuffer(GLuint vao, GLuint vbo, int index)
{
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(
		index,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
}

double GetCurTime() {
	return glfwGetTime();
}

double GetDeltaTime() {
	static double lasttime = 0.0;
	double curtime = GetCurTime();
	double deltatime = curtime - lasttime;
	lasttime = curtime;
	cout << "上一帧使用时间:" << deltatime<<endl;
	return deltatime;
}

mat4 GetBaseMVP() {
	//加入全局变换矩阵
	// Projection matrix : 45?Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, -3), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
	PrintMat4(MVP);
	return MVP;
}

Vertexs TriangleToVertexs(vector<Triangle>& triangles) {
	Vertexs vertexs;
	int count = triangles.size() * 3*3;
	vertexs.datas = new float[count];
	vertexs.count = count;
	int i = 0;
	for each (Triangle var in triangles)
	{
		Point x = var.x;		
		vertexs.datas[i] = x.x;
		vertexs.datas[i + 1] = x.y;
		vertexs.datas[i + 2] = x.z;
		Point y = var.y;
		vertexs.datas[i + 3] = y.x;
		vertexs.datas[i + 4] = y.y;
		vertexs.datas[i + 5] = y.z;
		Point z = var.z;
		vertexs.datas[i + 6] = z.x;
		vertexs.datas[i + 7] = z.y;
		vertexs.datas[i + 8] = z.z;
		i += 9;
	}
	return vertexs;
}

//rect-->>triangle-->vertexs
Vertexs RectToVertexs(vector<Rect>& rects) {
	vector<vector<Triangle>> datas;
	for each (Rect var in rects)
	{
		datas.push_back(var.Convert());
	}
	Vertexs v = TriangleToVertexs(Add(datas));
	return v;
}

Vertexs RectToVertexs(Rect rect) {
	return TriangleToVertexs(rect.Convert());
}