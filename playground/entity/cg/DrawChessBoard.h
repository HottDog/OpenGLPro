#pragma once
#include"playground/data/view/ChessBoard.h"
#include"playground/system/RectTask.h"
#include"playground/data/mesh/vertexs.h"
class DrawChessBoard :public RectTask
{
public:
	DrawChessBoard();
protected:
	virtual bool Start();
	virtual bool Draw();
	virtual bool Destroy();
private:
	ChessBoard chess;
};