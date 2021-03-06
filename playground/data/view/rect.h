#pragma once
#include"playground/data/mesh/vertexs.h"
#include"common/globalconfig.h"
#include"playground/data/mesh/point.h"
#include <math.h>
#include"playground/data/util/mathutil.h"
#include <glm/glm.hpp>
using namespace glm;
//矩形
//坐标系是左上角是原点，屏幕尺寸是1024*768
//关于旋转,默认绕(x,y)旋转,顺时针旋转
//旋转矩阵[cos(a),sin(a)
//       -sin(a),cos(a)]
class Rect {
public :
	enum TexFillType {
		Fill, Rele
	};
	
	static int ID ;

	Rect();
	// 参数说明：
	// x,y 左上角坐标
	// w 为宽度 , h 为高度
	Rect(float x, float y, float w, float h);
	int id;
	vector<Triangle> Convert();
	Mesh GetMesh();
	float w;
	float h;
	float x;
	float y;
	
	float angle = 0;  //角度度数
	TexFillType texFillType = Fill;
	char * image = "res/white.jpg";
	vec3 color = vec3(1.0f,1.0f,1.0f);
	Point topLeft;
	Point topRight;
	Point bottomRight;
	Point bottomLeft;

	void Process();

	void Rotate();	
	
	Indexs CreateIndexs();
	//Point Rotate(Point& t, float a);
	UVs GetUVs();

	UVs GetFillUVs();

	UVs GetRelaUVs();

	
};