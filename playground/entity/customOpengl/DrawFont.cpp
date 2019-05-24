#include"DrawFont.h"
#include<ft2build.h>
#include"playground/data/view/rect.h"
#include"playground/entity/util/ShowUtil.h"

#include"playground/entity/util/DrawUtil.h"
#include FT_FREETYPE_H
DrawSomeFont::DrawSomeFont() {

}

bool DrawSomeFont::Start() {
	NormalTask::Start();
	LoadFont();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	shader = GetDefaultShaderWithoutSuffix("Font");
	lineShader = GetDefaultShaderWithoutSuffix("test");
	//glUseProgram(shader);
	VAO = CreateVAO(1);
	VBO = CreateVBO(1);
	UV = CreateVBO(1);
	EBO = CreateEBO(1);

	//׼��font����
	font = Font(vec2(100, 100), 50, "this is my font");
	font.CreateAllChilds(characters);
	
	return true;
}

bool DrawSomeFont::Draw() {
	NormalTask::Draw();

	

	for each (Font::FontItem var in font.childs)
	{
		DrawFontItem(var, font.color, VAO, VBO, UV, EBO, shader);
	}

	int count = font.content.size();
	for (int i = 0; i < count; i++) {
		DrawRectLine(Rect(font.base.x + i * font.base.w, font.base.y, font.base.w, font.base.h), VAO,
			VBO, UV, EBO, lineShader);
	}
	
	return true;
}

bool DrawSomeFont::Destroy() {
	NormalTask::Destroy();
	return true;
}

void DrawSomeFont::DrawAChar() {
	Rect rect(100, 100, 40, 40);
	Vertexs v = rect.GetMesh().vertexs;
	VBOBindData(VBO, v.datas, v.count * 4);
	//PrintVertexs(v, 2);
	delete v.datas;
	VAOBindBuffer(VAO, VBO, 0);

	UVs uvs = rect.GetMesh().uvs;
	VBOBindData(UV, uvs.datas, uvs.count * 4);
	//PrintVertexs(uvs, 1);
	delete uvs.datas;
	VAOBindBuffer(VAO, UV, 1, 2);

	Indexs indexs = rect.GetMesh().indexs;
	EBOBindData(EBO, indexs.datas, indexs.count * 4);
	delete indexs.datas;


	vec3 color(1, 0, 0);
	//����textColorֵ
	glUniform3f(glGetUniformLocation(shader, "texColor"), color.x, color.y, color.z);
	//���������ͼ
	glBindTexture(GL_TEXTURE_2D, characters['Y'].textureID);
	glActiveTexture(GL_TEXTURE0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
	GLenum en = glGetError();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

//FreeType�������¾��Ǽ���TrueType���岢Ϊÿһ����������λͼ�Լ����㼸������ֵ(Metric)��
//���ǿ�����ȡ�������ɵ�λͼ��Ϊ���ε�������ʹ����Щ����ֵ��λ�ַ������Ρ�
//Ҫ����һ�����壬����ֻ��Ҫ��ʼ��FreeType�⣬���ҽ�����������Ϊһ��FreeType��֮Ϊ��(Face)�Ķ�����
bool DrawSomeFont::LoadFont() {
	FT_Library ft;
	if (FT_Init_FreeType(&ft)) {
		cout<< "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
		return false;
	}
	FT_Face face;
	if (FT_New_Face(ft, "res/Fonts/arial.ttf", 0, &face)) {
		cout<< "ERROR::FREETYPE: Failed to load font" << std::endl;
		return false;
	}
	//�˺���������������Ŀ�Ⱥ͸߶ȣ������ֵ��Ϊ0��ʾ����Ҫ��������ͨ�������ĸ߶��ж�̬��������εĿ��
	FT_Set_Pixel_Sizes(face, 0, 48);

	//if (FT_Load_Char(face, 'X', FT_LOAD_RENDER)) {
	//	cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
	//	return false;
	//}

	//OpenGLҪ�����е�������4�ֽڶ���ģ�������Ĵ�С��Զ��4�ֽڵı�����
	//ͨ���Ⲣ�������ʲô���⣬��Ϊ�󲿷�����Ŀ�ȶ�Ϊ4�ı�����/��ÿ����ʹ��4���ֽڣ�������������ÿ������ֻ����һ���ֽڣ�������������Ŀ�ȡ�
	//ͨ���������ѹ���������Ϊ1����������ȷ�������ж������⣨�����ܻ���ɶδ��󣩡�
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //�����ֽڶ�������
	for (GLubyte c = 0; c < 128; c++) {
		//�����ַ�������
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			cout << "ERROR::FREETYTPE: Failed to load Glyph,this char is ["<<c <<"]"<< std::endl;
			continue;
		}
		GLuint tex = CreateTexture(1);
		glBindTexture(GL_TEXTURE_2D,tex);
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
		//��������ѡ��
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
		characters.insert(pair<GLchar ,Character>(c, character));
	}
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
	return true;
}