#pragma once
#include"DataUtil.h"
#include"common/opengltool.h"
#include"playground/view/Font.h"
void DrawMesh(Mesh & mesh, GLuint vao, GLuint vertex, GLuint uv);

void DrawRect(Rect & rect,RectOG& ogdata);

void DrawRect(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint texture, GLuint shader);

void DrawRectLine(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader);

void DrawFont(Font font,GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader);

void DrawFontItem(Font::FontItem item, vec3 color, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader);

