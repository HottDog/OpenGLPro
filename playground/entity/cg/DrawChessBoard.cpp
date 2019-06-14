#include"DrawChessBoard.h"

#include"playground/entity/util/DrawUtil.h"
#include<map>;
DrawChessBoard::DrawChessBoard()
{

}

bool DrawChessBoard::Start()
{
	RectTask::Start();
	chess = ChessBoard(vec2(500,300));
	chess.DiffRectsWithColor();
	return true;
}

bool DrawChessBoard::Draw()
{
	RectTask::Draw();
	map<vec3, vector<Rect>>::iterator it = chess.diffRects.begin();
	while (it != chess.diffRects.end())
	{
		DrawRects(it->second, ogdata);
		it++;
	}
	return true;
}

bool DrawChessBoard::Destroy()
{
	RectTask::Destroy();
	return true;
}