#pragma once
#include"playground/data/util/DataUtil.h"
#include"common/opengltool.h"
#include"playground/data/view/Font.h"
#include<vector>
void DrawMesh(Mesh & mesh, RectOG ogObj);

void DrawRect(Rect & rect,RectOG& ogdata);

void DrawRect(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint texture, GLuint shader);

void DrawRect(Mesh & mesh,vec3& color, char * image, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint texture, GLuint shader);

void DrawRectLine(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader);

void DrawRects(vector<Rect> rects, RectOG ogObj);

void DrawFont(Font& font, RectOG& ogdata);

void DrawFont(Font& font,GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader);

void DrawFontItem(Font::FontItem item, vec3 color, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint shader);

