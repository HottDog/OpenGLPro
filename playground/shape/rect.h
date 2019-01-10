#pragma once
#include"playground/data/vertexs.h"
#include"common/globalconfig.h"
#include"playground/data/point.h"
#include <math.h>
#include"playground/util/mathutil.h"
//矩形
//坐标系是左上角是原点，屏幕尺寸是1024*768
//关于旋转,默认绕(x,y)旋转,顺时针旋转
//旋转矩阵[cos(a),sin(a)
//       -sin(a),cos(a)]
class Rect {
public :
	static int ID ;
	Rect();
	Rect(float x, float y, float w, float h);
	int id;
	vector<Triangle> Convert();
	float w;
	float h;
	float x;
	float y;
	
	float angle = 0;  //角度度数

	Point topLeft;
	Point topRight;
	Point bottomRight;
	Point bottomLeft;

	void Process();
private:	
	//转化成opengl的x坐标
	float ToX(float posx);
	//转化成opengl的y坐标
	float ToY(float posy);

	Point ToPos(Point & point);

	//Point Rotate(Point& t, float a);

};