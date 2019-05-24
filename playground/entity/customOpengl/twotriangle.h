#pragma once
#include"playground/system/normaltask.h"
#include"common/opengltool.h"
#include"playground/data/util/rectutil.h"
class TwoTriangle :public NormalTask {
public:
	TwoTriangle();

	void SegaAllRects();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();

private:
	GLuint VAO;
	GLuint VBO;
	GLuint VBO2;
	GLuint shader;
	vector<Rect> rects;
	int rectNum = 0;
	
	void _AddRect(Rect& r);
	void _AddRects(vector<Rect>& rs);
	void _RemoveRect(Rect& r);
	void _CleanRects();
};