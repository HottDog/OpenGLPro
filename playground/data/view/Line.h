#pragma once
#include"rect.h"
class Line
{
public :
	Line(float leftX, float leftY, float rightX, float rightY);
	Rect GetRect();

	void SetSize(float size);
private :
	Rect rect;
	
};