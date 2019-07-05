#include"DrawChessBoard.h"

#include"playground/entity/util/DrawUtil.h"
#include<map>;
#include"playground/data/config/Color.h"
#include"playground/data/draw/DrawLine.h"
DrawChessBoard::DrawChessBoard()
{

}

bool DrawChessBoard::Start()
{
	RectTask::Start();
	lineshader = GetDefaultShaderWithoutSuffix("test");
	rectshader = ogdata.shader;
	chess = ChessBoard(vec2(250,90));
	//chess.SetColor(100, 100, Color::WHITE);
	//chess.SetColor(100, 1, Color::GREEN);
	//chess.SetColor(1, 100, Color::WHITE);
	//chess.SetColor(1, 1, Color::RED);
	//DDA(chess, vec2(2, 3), vec2(22, 12));
	//DDA(chess, vec2(19, 4), vec2(8, 8));
	//DDA(chess, vec2(22, 18), vec2(2, 8));
	//DDA(chess, vec2(27, 27), vec2(20, 20));
	//DDA(chess, vec2(3, 27), vec2(8,22));
	//DDA(chess, vec2(5.6, 27.4), vec2(11.5, 29.5));
	//BresenhamX(chess, 1, 1, 21, 20);
	//BresenhamY(chess, 1, 1, 5, 22);
	//DDA(chess, vec2(4, 1), vec2(8, 22));
	//DDA(chess, vec2(2, 6), vec2(27, 26));
	//Bresenham(chess, vec2(3, 2), vec2(20, 3));
	//Bresenham(chess, vec2(2, 4), vec2(13, 7));
	//Bresenham(chess, vec2(13, 7), vec2(2, 4));
	//Bresenham(chess, vec2(2, 4), vec2(8, 16));
	//Bresenham(chess, vec2(8, 16), vec2(2, 4));
	//Bresenham(chess, vec2(2, 23), vec2(20, 3));
	//Bresenham(chess, vec2(20, 10), vec2(30, 18));
	//Bresenham(chess, vec2(2, 2), vec2(6, 23));
	//Bresenham(chess, vec2(8, 23), vec2(4, 2));
	//Bresenham(chess, vec2(4, 2), vec2(8, 23));
	//Bresenham(chess, vec2(18, 6), vec2(4, 2));
	//Bresenham(chess, vec2(4, 2), vec2(18, 6));
	//Bresenham(chess, vec2(15,15),5);
	CutoffLine();
	chess.DiffRectsWithColor();
	return true;
}

bool DrawChessBoard::Draw()
{
	RectTask::Draw();
	ogdata.shader = rectshader;
	for(int i =0 ;i<chess.diffRects.size();i++)
	{  
		DrawRects(chess.diffRects[i].rects, ogdata);
	}
	ogdata.shader = lineshader;
	DrawRectLines(chess.rects, ogdata);
	return true;
}

bool DrawChessBoard::Destroy()
{
	RectTask::Destroy();
	return true;
}

void DrawChessBoard::CutoffLine()
{
	//绘制一条线段
	Bresenham(chess, vec2(8, 23), vec2(4, 2));
	//绘制一个裁剪矩形框
	int xmin = 3;
	int xmax = 15;
	int ymin = 10;
	int ymax = 20;
	Bresenham(chess, vec2(xmin, ymin), vec2(xmin, ymax));
	Bresenham(chess, vec2(xmin, ymax), vec2(xmax, ymax));
	Bresenham(chess, vec2(xmax, ymin), vec2(xmax, ymax));
	Bresenham(chess, vec2(xmax, ymin), vec2(xmin, ymin));
}