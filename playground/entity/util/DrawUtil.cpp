#include"playground/entity/util/DrawUtil.h"
#include"playground/entity/util/ShowUtil.h"
#include"common/shadertool.h"
#include"common/opengltool.h"
#include"playground/entity/runtime/RunTime.h"
#include"playground/data/util/DataUtil.h"
void DrawMesh(Mesh & mesh, RectOG ogObj) {
	glUseProgram(ogObj.shader);
	Vertexs v = mesh.vertexs;
	VBOBindData(ogObj.vertex, v.datas, v.count * 4);
	//PrintVertexs(v, 2);
	//delete v.datas;
	VAOBindBuffer(ogObj.vao, ogObj.vertex, 0);

	UVs uvs = mesh.uvs;
	VBOBindData(ogObj.uv, uvs.datas, uvs.count * 4);
	//PrintVertexs(uvs, 1);
	//delete uvs.datas;
	VAOBindBuffer(ogObj.vao, ogObj.uv, 1, 2);

	//Indexs indexs = mesh.indexs;
	//EBOBindData(ogObj.ebo, indexs.datas, indexs.count * 4);
	//delete indexs.datas;

	//设置颜色
	//SetShaderData(shader, "rectColor", rect.color);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawArrays(GL_TRIANGLES, 0, v.count);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void DrawRects(vector<Rect> rects, RectOG ogdata)
{
	vector<Mesh> meshs;
	for (int i = 0; i < rects.size(); i++)
	{
		meshs.push_back(rects[i].GetMesh());
	}
	DrawRect(MergeMesh(meshs), rects[0].color, rects[0].image, ogdata.vao, ogdata.vertex, ogdata.uv, ogdata.index, ogdata.texture, ogdata.shader);
}

void DrawRect(Rect & rect, RectOG& ogdata) {
	DrawRect(rect.GetMesh(),rect.color,rect.image, ogdata.vao, ogdata.vertex, ogdata.uv, ogdata.index, ogdata.texture,ogdata.shader);
}

void DrawRect(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint texture, GLuint shader)
{
	DrawRect(rect.GetMesh(), rect.color, rect.image, vao,vertex, uv, ebo, texture, shader);
}

void DrawRect(Mesh & mesh,vec3& color,char * image, GLuint vao, GLuint vertex, GLuint uv,GLuint ebo,GLuint texture,GLuint shader) {
	glUseProgram(shader);

	Vertexs v = mesh.vertexs;
	VBOBindData(vertex, v.datas, v.count * 4);
	//PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(vao, vertex, 0);
	
	UVs uvs = mesh.uvs;
	VBOBindData(uv, uvs.datas, uvs.count * 4);
	//PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(vao, uv, 1, 2);

	Indexs indexs = mesh.indexs;
	EBOBindData(ebo, indexs.datas, indexs.count * 4);
	delete indexs.datas;

	//设置颜色
	SetShaderData(shader,"rectColor",color);


	//准备图片资源
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char * data = stbi_load(image, &width, &height, &nrChannels, 0);
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

void DrawRectLine(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader) {
	//
	glUseProgram(shader);
	Vertexs v = rect.GetMesh().vertexs;
	VBOBindData(vertex, v.datas, v.count * 4);
	//PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(vao, vertex, 0);

	UVs uvs = rect.GetMesh().uvs;
	VBOBindData(uv, uvs.datas, uvs.count * 4);
	//PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(vao, uv, 1, 2);

	Indexs indexs = rect.GetMesh().indexs;
	EBOBindData(ebo, indexs.datas, indexs.count * 4);
	delete indexs.datas;

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//用线框模式绘图
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
	GLenum en = glGetError();
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	//关闭用线框模式绘图
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void DrawFont(Font& font, RectOG& ogdata)
{	
	ogdata.shader = GetDefaultShaderWithoutSuffix("Font");
	font.Init(LoadFont());
	DrawFont(font, ogdata.vao, ogdata.vertex, ogdata.uv, ogdata.index, ogdata.shader);
}

void DrawFont(Font& font, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader) {
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
	//PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(vao, vertex, 0);

	UVs uvs = rect.GetMesh().uvs;
	VBOBindData(uv, uvs.datas, uvs.count * 4);
	//PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(vao, uv, 1, 2);

	Indexs indexs = rect.GetMesh().indexs;
	EBOBindData(ebo, indexs.datas, indexs.count * 4);
	delete indexs.datas;

	//vec3 color(1, 0, 0);
	//传入textColor值
	glUniform3f(glGetUniformLocation(shader, "texColor"), color.x, color.y, color.z);
	glBindTexture(GL_TEXTURE_2D, character.textureID);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
	GLenum en = glGetError();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}