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

	//准备font数据
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
	//传入textColor值
	glUniform3f(glGetUniformLocation(shader, "texColor"), color.x, color.y, color.z);
	//绑定字体的贴图
	glBindTexture(GL_TEXTURE_2D, characters['Y'].textureID);
	glActiveTexture(GL_TEXTURE0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
	GLenum en = glGetError();
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

//FreeType所做的事就是加载TrueType字体并为每一个字形生成位图以及计算几个度量值(Metric)。
//我们可以提取出它生成的位图作为字形的纹理，并使用这些度量值定位字符的字形。
//要加载一个字体，我们只需要初始化FreeType库，并且将这个字体加载为一个FreeType称之为面(Face)的东西。
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
		characters.insert(pair<GLchar ,Character>(c, character));
	}
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
	return true;
}