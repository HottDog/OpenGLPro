#include"playground/customOpengl/DrawPicture.h"
#include"playground/util/ShowUtil.h"
DrawPicture::DrawPicture() {

}

bool DrawPicture::Start() {
	NormalTask::Start();

	shader = GetDefaultShaderWithoutSuffix("DrawPicture");
	VAO = CreateVAO(1);
	VBO = CreateVBO(1);
	UV = CreateVBO(1);
	EBO = CreateEBO(1);
	texture = CreateTexture(1);

	Rect rect(200, 200, 700, 500);
	rect.texFillType = Rect::Fill;
	drawData.AddRect(rect);

	Vertexs vertexs = drawData.ToVertexs(true);
	VBOBindData(VBO, vertexs.datas, vertexs.count*4);
	PrintVertexs(vertexs,2);
	delete vertexs.datas;
	VAOBindBuffer(VAO, VBO, 0);

	UVs uvs = drawData.ToUVs();
	VBOBindData(UV, uvs.datas, uvs.count * 4);
	PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(VAO, UV, 1, 2);

	Indexs indexs = drawData.ToIndexs();
	EBOBindData(EBO, indexs.datas, indexs.count * sizeof(unsigned int));
	PrintVertexs(indexs,2);
	delete indexs.datas;
	
	//准备图片资源
	int width, height, nrChannels;
	unsigned char * data = stbi_load("res/container.jpg", &width, &height, &nrChannels, 0);
	TextureBindData(texture, 0, width, height, data);
	stbi_image_free(data);   //释放图片数据内存
	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return true;
}

bool DrawPicture::Draw() {
	NormalTask::Draw();
	
	glUseProgram(shader);
	
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT , (void*)0);
	GLenum en = glGetError();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	return true;
}

bool DrawPicture::Destroy() {
	NormalTask::Destroy();

	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &UV);
	glDeleteProgram(shader);
	glDeleteVertexArrays(1, &VAO);

	glDeleteBuffers(1, &EBO);
	return true;
}