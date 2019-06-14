#include"opengltool.h"
#include<ft2build.h>
#include FT_FREETYPE_H
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

void VAOBindBuffer(GLuint vao,GLuint vbo, int index,int size )
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindVertexArray(vao);
	glVertexAttribPointer(
		index,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		size,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
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

GLuint CreateEBO(int index) {
	GLuint elementBuffer;
	glGenBuffers(index, &elementBuffer);
	cout << "EBO(id):" << elementBuffer << endl;
	return elementBuffer;
}

void EBOBindData(GLuint ebo, const unsigned int* data, int size) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

GLuint CreateTexture(int index) {
	GLuint texture;
	glGenTextures(index, &texture);
	//cout << "Texture(id):" << texture << endl;
	return texture;
}

void TextureBindData(GLuint texture, int level, int width, int height, unsigned char * data) {
	glBindTexture(GL_TEXTURE_2D,texture);
	glTexImage2D(GL_TEXTURE_2D, level, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
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

GLuint GetDefaultShaderWithoutSuffix(char * shadername) {
	string vert_str(shadername);
	vert_str = "shader/" + vert_str + ".vert";
	string frag_str(shadername);
	frag_str = "shader/" + frag_str + ".frag";
	return LoadShaders(vert_str.c_str(), frag_str.c_str());
}

//FreeType所做的事就是加载TrueType字体并为每一个字形生成位图以及计算几个度量值(Metric)。
//我们可以提取出它生成的位图作为字形的纹理，并使用这些度量值定位字符的字形。
//要加载一个字体，我们只需要初始化FreeType库，并且将这个字体加载为一个FreeType称之为面(Face)的东西。
map<GLchar, Character> LoadFont(char * fontpath ) {
	map<GLchar, Character> result;
	FT_Library ft;
	if (FT_Init_FreeType(&ft)) {
		cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		return result;
	}
	FT_Face face;
	if (FT_New_Face(ft, fontpath, 0, &face)) {
		cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
		return result;
	}
	//此函数设置了字体面的宽度和高度，将宽度值设为0表示我们要从字体面通过给定的高度中动态计算出字形的宽度
	FT_Set_Pixel_Sizes(face, 0, 48);

	//if (FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
	//	cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
	//	return false;
	//}

	//OpenGL要求所有的纹理都是4字节对齐的，即纹理的大小永远是4字节的倍数。
	//通常这并不会出现什么问题，因为大部分纹理的宽度都为4的倍数并/或每像素使用4个字节，但是现在我们每个像素只用了一个字节，它可以是任意的宽度。
	//通过将纹理解压对齐参数设为1，这样才能确保不会有对齐问题（它可能会造成段错误）。
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //禁用字节对齐限制
	for (GLubyte c = 0; c < 128; c++) {
		//加载字符的字形
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			cout << "ERROR::FREETYTPE: Failed to load Glyph,this char is [" << c << "]" << std::endl;
			continue;
		}
		GLuint tex = CreateTexture(1);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer);
		//设置纹理选项
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		Character character = {
			c,
			tex,
			ivec2(face->glyph->bitmap.width,face->glyph->bitmap.rows),
			ivec2(face->glyph->bitmap_left,face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		result.insert(pair<GLchar, Character>(c, character));
	}
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
	return result;
}

void InitRectOG(RectOG & ogdata)
{
	ogdata.vao = CreateVAO(1);
	ogdata.vertex = CreateVBO(1);
	ogdata.uv = CreateVBO(1);
	ogdata.index = CreateEBO(1);
	ogdata.texture = CreateTexture(1);
}

void DeleteRectOG(RectOG & ogdata) {
	glDeleteBuffers(1, &ogdata.vertex);
	glDeleteBuffers(1, &ogdata.uv);
	glDeleteBuffers(1, &ogdata.index);
	glDeleteProgram(ogdata.shader);
	glDeleteVertexArrays(1, &ogdata.vao);
}
