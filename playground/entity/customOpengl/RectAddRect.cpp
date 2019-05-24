#include"RectAddRect.h"
RectAddRect::RectAddRect() {
	isClearFrame = false;
	isAutoRefreshFrame = false;
}

bool RectAddRect::Start() {
	NormalTask::Start();
	shader = GetDefaultShaderWithoutSuffix("test");
	VAO = CreateVAO(1);
	VBO = CreateVBO(1);
	
	Rect rect1(x, 100, 500, 500);
	//Vertexs v = RectToVertexs(rect1);
	drawData.AddRect(rect1);
	Vertexs v = drawData.ToVertexs();	
	VBOBindData(VBO, v.datas, v.count * 4);
	delete v.datas;
	_DrawFrame();
	return true;
}

bool RectAddRect::Draw() {
	//_DrawFrame();
	return NormalTask::Draw();
	
	
	//double deletaTime = GetDeltaTime();
	//runTime += deletaTime;
	/*if (runTime > 4) {
		runTime = 0;
		x += 120;
		Rect rect1(x, 100, 100, 100);
		drawData.CleanRects();
		drawData.AddRect(rect1);
		Vertexs v = drawData.ToVertexs();
		VBOBindData(VBO, v.datas, v.count * 4);
	}*/
	//��VBO
	
	
	//����������
	//glfwSwapBuffers(window);
	if (x > 99) {
		
		
		//if (ss == 0) {
			x--;
			
		glUseProgram(shader);
		//��VAO
		VAOBindBuffer(VAO,VBO, 0);
		//����VAO
		glEnableVertexAttribArray(0);
		GLenum ss = glGetError();
		
		
		glDrawArrays(GL_TRIANGLES, 0, 3 * drawData.rectCount * 2);
		
		glfwSwapBuffers(window);
		//�ر�VAO
		glDisableVertexAttribArray(0);
		//}
	}
	
	
	return true;
}

bool RectAddRect::Destroy() {
	NormalTask::Destroy();
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shader);
	glDeleteVertexArrays(1, &VAO);
	return true;
}

void RectAddRect::_DrawFrame() {
	
	glUseProgram(shader);
	//��VAO
	VAOBindBuffer(VAO,VBO, 0);
	//����VAO
	glEnableVertexAttribArray(0);
	//���Ƶ�һ������
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, 3 * drawData.rectCount * 2);
	for (int i = 0; i < 0; i++) {
		x += 120;
		Rect rect1(x, 100, 100, 100);
		drawData.CleanRects();
		drawData.AddRect(rect1);
		
		Vertexs v = drawData.ToVertexs();
		//��������һ��drawcall
		VBOBindData(VBO, v.datas, v.count * 4);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, 0, 3 * drawData.rectCount * 2);
	}
	//�ر�VAO
	glDisableVertexAttribArray(0);
	glfwSwapBuffers(window);
}