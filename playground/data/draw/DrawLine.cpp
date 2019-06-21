#include"DrawLine.h"
#include<math.h>
void DDA(ChessBoard& chess,vec2 start,vec2 end)
{
	//先取整
	int startx = round(start.x);
	int starty = round(start.y);
	int endx = round(end.x);
	int endy = round(end.y);
	float ky = float(endy - starty);
	float kx = float(endx-startx);
	float k;
	float dx,dy;
	int num;
	
	if (fabs(ky) > fabs(kx))
	{
		//y增
		dx = kx / fabs(ky);  //可能比较耗
		dy = endy>starty?1:-1;
		num = abs(endy - starty);
	}
	else
	{
		dx = endx>startx?1:-1;
		dy = ky / fabs(kx);   //可能比较耗
		num = abs(endx - startx);
	}
	//渲染起始点
	chess.SetColor(startx, starty);
	float x = startx;
	float y = starty;
	for (int i = 0; i < num; i++)
	{
		x += dx;
		y += dy;
		chess.SetColor(round(x), round(y));
	}

}

void Bresenham(ChessBoard& chess, vec2 start, vec2 end)
{
	//先取整
	int startx = round(start.x);
	int starty = round(start.y);
	int endx = round(end.x);
	int endy = round(end.y);
	int dx = endx - startx;
	int dy = endy - starty;
	int num = 0;
	bool isSymX = false;
	int symValue = 0;
	vec2 * result;
	if (fabs(dy) > fabs(dx))
	{
		num = abs(dy);
		if (endy >= starty)
		{
			if (endx >= startx)
			{
				result = BresenhamY(chess, startx, starty, endx, endy);
			}
			else
			{
				isSymX = true;
				int tempstarty = endy + abs(endy - starty);
				symValue = endy;
				result = BresenhamY(chess, endx, endy, startx, tempstarty);				
			}
			
		}
		else
		{
			
			if (endx >= startx)
			{
				//先算出跟x = startx轴对称的线段，然后再对称回来
				isSymX = true;
				int tempendy = starty + abs(endy - starty);
				symValue = starty;
				result = BresenhamY(chess, startx, starty, endx, tempendy);
			}
			else
			{
				result = BresenhamY(chess, endx, endy, startx, starty);
			}
			
		}
		
	}
	else
	{
		num = abs(dx);
		if (endy >= starty)
		{
			if (endx >= startx)
			{
				result = BresenhamX(chess, startx, starty, endx, endy);
			}
			else
			{
				isSymX = true;
				int tempstarty = endy + abs(endy - starty);
				symValue = endy;
				result = BresenhamX(chess, endx, endy, startx, tempstarty);
			}
		}
		else
		{
			
			//先算出跟x = startx轴对称的线段，然后再对称回来
			if (endx >= startx)
			{
				isSymX = true;
				int tempendy = starty + abs(endy - starty);
				symValue = starty;
				result = BresenhamX(chess, startx, starty, endx, tempendy);
			}
			else
			{
				
				result = BresenhamX(chess, endx, endy, startx, starty);
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (isSymX)
		{
			int tempy = symValue - abs(result[i].y - symValue);
			chess.SetColor(result[i].x, tempy);
		}
		else
		{
			chess.SetColor(result[i].x, result[i].y);
		}
	}
}

vec2 * BresenhamX(ChessBoard& chess, int startx, int starty, int endx, int endy)
{
	int dx = endx - startx;
	int dy = endy - starty;
	int p0 = 2 * dy - dx;
	int num = dx;
	vec2 * result = new vec2[num];
	//渲染起始点
	chess.SetColor(startx, starty);
	int p = p0;
	for (int i = 0; i < num; i++)
	{
		int tempy = p >= 0 ? 1 : 0;
		p = 2 * dy - 2 * dx*tempy + p;
		startx++;
		starty = p >= 0 ? starty+1 : starty;
		chess.SetColor(startx, starty);
		result[i] = vec2(startx, starty);
	}
	return result;
}

vec2* BresenhamY(ChessBoard& chess, int startx, int starty, int endx, int endy)
{
	 
	int dx = endx - startx;
	int dy = endy - starty;
	int p0 = 2 * dx - dy;
	int num = dy;
	vec2 * result = new vec2[num];
	//渲染起始点
	chess.SetColor(startx, starty);
	int p = p0;
	for (int i = 0; i < num; i++)
	{
		int tempy = p >= 0 ? 1 : 0;
		p = 2 * dx - 2 * dy*tempy + p;
		starty++;
		startx = p >= 0 ? startx + 1 : startx;
		//chess.SetColor(startx, starty);
		result[i] = vec2(startx, starty);
	}
	return result;
}

void Bresenham(ChessBoard & chess, vec2 center, float radius)
{	
	int x = round(center.x);
	int y = round(center.y);
	vec2 cen(x, y);
	int r = round(radius);
	y += r;
	float p = 5 / 4 - r;
	//绘制第一个点
	EightEqual(chess, vec2(x, y), cen,r);
	while (x <= y)
	{
		if (p > 0)
		{
			//取下面的点
			p = p + 2 * x - 2 * y + 5;
			y--;
		}
		else
		{
			//取上面的点
			p = p + 2 * x + 3;
		}
		x++; 
		EightEqual(chess, vec2(x, y), cen,r);
	}
}

void EightEqual(ChessBoard & chess, vec2 point,vec2 center,int r)
{
	chess.SetColor(point.x, point.y);
	//关于y=x轴对称
	vec2 yx (point.y - center.y + center.x, point.x - center.x + center.y);
	chess.SetColor(yx.x, yx.y);
	//上面两个点关于y = center.y轴对称
	vec2 x1(point.x, 2*center.y - point.y);
	vec2 x2(yx.x, 2 * center.y -yx.y);
	chess.SetColor(x1.x, x1.y);
	chess.SetColor(x2.x, x2.y);
	//上面四个点关于x = center.x轴对称
	chess.SetColor(2* center.x -point.x, point.y);
	chess.SetColor(2 * center.x -yx.x, yx.y);
	chess.SetColor(2 * center.x -x1.x, x1.y);
	chess.SetColor(2 * center.x -x2.x, x2.y);

}

void Offset(ChessBoard & chess, vec2 point, vec2 center)
{
	chess.SetColor(point.x + center.x, point.y + center.y);
}