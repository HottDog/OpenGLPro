#pragma once
// Include GLM
#include <glm/glm.hpp>
#include"playground/data/config/Color.h"
#include"rect.h"
#include<vector>
#include<map>
#include"playground/data/viewdata/Vec3MapRect.h"
using namespace std;
using namespace glm;

class ChessBoard
{
public:
	ChessBoard();
	ChessBoard(vec2 p, float s = 15);
	vec2 pos = vec2(0,0);
	float size = 15;
	int width = 30;
	int height = 30;
	vec3 ** colors;
	vector<Rect> rects;
	vector<Vec3MapRect> diffRects;
	//按颜色将所有的矩形进行分类
	void DiffRectsWithColor();
	void SetColor(int w, int h, vec3 c = Color::GREEN);
private :
	void InitColors();
	void ProcessRects();
	
};