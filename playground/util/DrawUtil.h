#pragma once
#include"DataUtil.h"
#include"common/opengltool.h"
void DrawMesh(Mesh & mesh, GLuint vao, GLuint vertex, GLuint uv);

void DrawRect(Rect & rect, GLuint vao, GLuint vertex, GLuint uv, GLuint ebo, GLuint texture);