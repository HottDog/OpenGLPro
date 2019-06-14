#include"ChessBoard.h"
ChessBoard::ChessBoard()
{
	InitColors();
	ProcessRects();
}

ChessBoard::ChessBoard(vec2 p, float s)
{
	pos = p;
	size = s;
	InitColors();
	ProcessRects();
}

void ChessBoard::InitColors()
{
	colors = new vec3*[height];
	for (int i = 0; i < height; i++)
	{
		vec3 * p = new vec3[width];
		for (int j = 0; j < width; j++)
		{
			p[j] = Color::BLACK;
		}
		colors[i] = p;
	}
}

void ChessBoard::ProcessRects()
{
	for (int i = 0; i < height; i++)
	{
		vec2 posTemp;
		posTemp.y = pos.y + i * size;
		for (int j = 0; j < width; j++)
		{
			posTemp.x = pos.x + j*size;
			Rect rect = Rect(posTemp.x, posTemp.y, size, size);
			rect.color = colors[i][j];
			rects.push_back(rect);
		}
	}
}

void ChessBoard::DiffRectsWithColor()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			vec3 color = colors[i][j];
			if(diffRects.find(color) ==diffRects.end())
			{
				vector<Rect> rectsTmp;
				//Ã»ÓÐkey
				diffRects.insert(pair<vec3, vector<Rect>>(color, rectsTmp));
			}
			diffRects[color].push_back(rects[j + i * width]);
		}
	}
}
