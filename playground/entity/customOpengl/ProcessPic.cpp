#include"ProcessPic.h"
#include"playground/entity/util/DrawUtil.h"
#include"common/shadertool.h"
ProcessPic::ProcessPic() {

}

bool ProcessPic::Start() {
	RectTask::Start();
	//proShader = GetDefaultShaderWithoutSuffix("picProcess/filter1");
	proShader = GetDefaultShaderWithoutSuffix("picProcess/Pencil");
	defaultShader = GetDefaultShaderWithoutSuffix("DrawPicture");
	ogdata.shader = proShader;
	ogdata.texture2 = CreateTexture(1);
	ogdata.texture3 = CreateTexture(1);
	glUseProgram(ogdata.shader);
	return true;
}

bool ProcessPic::Draw() {
	RectTask::Draw();   
	Rect rect(50, 100, 450, 300);
	rect.image = "res/yasuo.jpg";
	ogdata.shader = defaultShader;
	DrawRect(rect, ogdata);

	Rect rect1(530, 100, 450, 300);
	rect1.image = "res/yasuo.jpg";
	ogdata.shader = proShader;
	DrawRect(rect1, ogdata);
	//DrawThreePic(rect1);
	return true;
}

bool ProcessPic::Destroy() {
	RectTask::Destroy();
	return true;
}

void ProcessPic::DrawThreePic(Rect rect)
{
	glUseProgram(ogdata.shader);
	Vertexs v = rect.GetMesh().vertexs;
	VBOBindData(ogdata.vertex, v.datas, v.count * 4);
	//PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(ogdata.vao, ogdata.vertex, 0);

	UVs uvs = rect.GetMesh().uvs;
	VBOBindData(ogdata.uv, uvs.datas, uvs.count * 4);
	//PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(ogdata.vao, ogdata.uv, 1, 2);

	Indexs indexs = rect.GetMesh().indexs;
	EBOBindData(ogdata.index, indexs.datas, indexs.count * 4);
	delete indexs.datas;

	//设置颜色
	SetShaderData(ogdata.shader, "rectColor", rect.color);


	//准备图片资源
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char * data = stbi_load("res/face1.jpg", &width, &height, &nrChannels, 0);
	TextureBindData(ogdata.texture, 0, width, height, data);
	stbi_image_free(data);   //释放图片数据内存

	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("res/face2.jpg", &width, &height, &nrChannels, 0);
	TextureBindData(ogdata.texture2, 0, width, height, data);
	stbi_image_free(data);   //释放图片数据内存

	stbi_set_flip_vertically_on_load(true);
	data = stbi_load("res/face3.jpg", &width, &height, &nrChannels, 0);
	TextureBindData(ogdata.texture3, 0, width, height, data);
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