#include"playground/util/DrawUtil.h"
#include"playground/util/ShowUtil.h"
void DrawMesh(Mesh & mesh, GLuint vao, GLuint vertex, GLuint uv) {

}

void DrawRect(Rect & rect, GLuint vao, GLuint vertex, GLuint uv,GLuint ebo,GLuint texture) {
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

	//准备图片资源
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char * data = stbi_load(rect.image, &width, &height, &nrChannels, 0);
	TextureBindData(texture, 0, width, height, data);
	stbi_image_free(data);   //释放图片数据内存
	// 为当前绑定的纹理对象设置环绕、过滤方式
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