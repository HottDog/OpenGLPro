#pragma once
#include"playground/data/view/ChessBoard.h"
void DDA(ChessBoard& chess, vec2 start, vec2 end);

void Bresenham(ChessBoard& chess, vec2 start, vec2 end);

vec2 * BresenhamX(ChessBoard& chess, int startx,int starty,int endx,int endy);

vec2 * BresenhamY(ChessBoard& chess, int startx, int starty, int endx, int endy);

void Bresenham(ChessBoard & chess, vec2 center, float r);

void EightEqual(ChessBoard & chess, vec2 point, vec2 center,int r);

void Offset(ChessBoard & chess, vec2 point,vec2 center);