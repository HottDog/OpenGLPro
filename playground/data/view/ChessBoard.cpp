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
	diffRects.clear();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			vec3 color = colors[i][j];
			InsertRect(diffRects, color, rects[j + i * width]);
		}
	}
}

void ChessBoard::SetColor(int w, int h, vec3 c)
{
	w = w - 1;
	//h = h - 1;
	//w = width - w;
	h = height - h;
	colors[h][w] = c;
	rects[w + h * width].color = c;
}

void ChessBoard::SetColors(vec2 * datas, int length, vec3 c)
{
	for (int i = 0; i < length; i++)
	{
		SetColor(datas[i].x, datas[i].y, c);
	}
}