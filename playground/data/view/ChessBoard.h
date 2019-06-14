#pragma once
// Include GLM
#include <glm/glm.hpp>
#include"playground/data/config/Color.h"
#include"rect.h"
#include<vector>
#include<map>
using namespace std;
using namespace glm;
namespace std
{
	template<>
	struct less<vec3>
	{
		constexpr bool operator()(const vec3& _Left, const vec3& _Right) const
		{
			if (_Left.x < _Right.x)
			{
				return true;
			}
			if (_Left.y < _Right.y)
			{
				return true;
			}
			if (_Left.z < _Right.z)
			{
				return true;
			}
			return false;
		}
	};
}

class ChessBoard
{
public:
	ChessBoard();
	ChessBoard(vec2 p, float s = 5);
	vec2 pos = vec2(0,0);
	float size = 5;
	int width = 20;
	int height = 20;
	vec3 ** colors;
	vector<Rect> rects;
	map<vec3, vector<Rect>> diffRects;

	void DiffRectsWithColor();
private :
	void InitColors();
	void ProcessRects();
	
};