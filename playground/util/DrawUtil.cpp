#include"playground/util/DrawUtil.h"
#include"playground/util/ShowUtil.h"
void DrawMesh(Mesh & mesh, GLuint vao, GLuint vertex, GLuint uv) {

}

void DrawRect(Rect & rect, RectOG& ogdata) {
	DrawRect(rect, ogdata.vao, ogdata.vertex, ogdata.uv, ogdata.index, ogdata.texture,ogdata.shader);
}

void DrawRect(Rect & rect, GLuint vao, GLuint vertex, GLuint uv,GLuint ebo,GLuint texture,GLuint shader) {
	glUseProgram(shader);

	Vertexs v = rect.GetMesh().vertexs;
	VBOBindData(vertex, v.datas, v.count * 4);
	PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(vao, vertex, 0);
	
	UVs uvs = rect.GetMesh().uvs;
	VBOBindData(uv, uvs.datas, uvs.count * 4);
	PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(vao, uv, 1, 2);

	Indexs indexs = rect.GetMesh().indexs;
	EBOBindData(ebo, indexs.datas, indexs.count * 4);
	delete indexs.datas;

	//׼��ͼƬ��Դ
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char * data = stbi_load(rect.image, &width, &height, &nrChannels, 0);
	TextureBindData(texture, 0, width, height, data);
	stbi_image_free(data);   //�ͷ�ͼƬ�����ڴ�
	// Ϊ��ǰ�󶨵�����������û��ơ����˷�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
	GLenum en = glGetError();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void DrawRectLine(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader) {
	//
	glUseProgram(shader);
	Vertexs v = rect.GetMesh().vertexs;
	VBOBindData(vertex, v.datas, v.count * 4);
	PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(vao, vertex, 0);

	UVs uvs = rect.GetMesh().uvs;
	VBOBindData(uv, uvs.datas, uvs.count * 4);
	PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(vao, uv, 1, 2);

	Indexs indexs = rect.GetMesh().indexs;
	EBOBindData(ebo, indexs.datas, indexs.count * 4);
	delete indexs.datas;

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//���߿�ģʽ��ͼ
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
	GLenum en = glGetError();
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	//�ر����߿�ģʽ��ͼ
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void DrawFont(Font font, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader) {
	for each (Font::FontItem var in font.childs)
	{
		DrawFontItem(var, font.color, vao, vertex, uv, ebo, shader);
	}
}

void DrawFontItem(Font::FontItem item,vec3 color, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo,GLuint shader) {
	glUseProgram(shader);
	
	Rect rect = item.rect;
	Character character = item.character;

	Vertexs v = rect.GetMesh().vertexs;
	VBOBindData(vertex, v.datas, v.count * 4);
	PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(vao, vertex, 0);

	UVs uvs = rect.GetMesh().uvs;
	VBOBindData(uv, uvs.datas, uvs.count * 4);
	PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(vao, uv, 1, 2);

	Indexs indexs = rect.GetMesh().indexs;
	EBOBindData(ebo, indexs.datas, indexs.count * 4);
	delete indexs.datas;

	//vec3 color(1, 0, 0);
	//����textColorֵ
	glUniform3f(glGetUniformLocation(shader, "texColor"), color.x, color.y, color.z);
	glBindTexture(GL_TEXTURE_2D, character.textureID);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
	GLenum en = glGetError();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}