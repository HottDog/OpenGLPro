#pragma once
#include"playground/data/view/ChessBoard.h"
void DDA(ChessBoard& chess, vec2 start, vec2 end);

void DDA(vec2*& data, int & length, vec2 start, vec2 end);

void Bresenham(ChessBoard& chess, vec2 start, vec2 end);

void Bresenham(vec2 * data, int & length, vec2 start, vec2 end);

void BresenhamX(vec2 *& data,int&length, int startx,int starty,int endx,int endy);

void BresenhamY(vec2 *& data, int&length, int startx, int starty, int endx, int endy);

void Bresenham(ChessBoard & chess, vec2 center, float r);

void EightEqual(ChessBoard & chess, vec2 point, vec2 center,int r);

void Offset(ChessBoard & chess, vec2 point,vec2 center);