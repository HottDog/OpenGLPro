#pragma once
#include"playground/data/vertexs.h"
#include"common/globalconfig.h"
#include"playground/data/point.h"
#include <math.h>
#include"playground/util/mathutil.h"
#include <glm/glm.hpp>
using namespace glm;
//����
//����ϵ�����Ͻ���ԭ�㣬��Ļ�ߴ���1024*768
//������ת,Ĭ����(x,y)��ת,˳ʱ����ת
//��ת����[cos(a),sin(a)
//       -sin(a),cos(a)]
class Rect {
public :
	enum TexFillType {
		Fill, Rele
	};
	
	static int ID ;

	Rect();
	Rect(float x, float y, float w, float h);
	int id;
	vector<Triangle> Convert();
	Mesh GetMesh();
	float w;
	float h;
	float x;
	float y;
	
	float angle = 0;  //�Ƕȶ���
	TexFillType texFillType = Fill;
	char * image = "res/white.jpg";
	vec3 color = vec3(1.0f,1.0f,1.0f);
	Point topLeft;
	Point topRight;
	Point bottomRight;
	Point bottomLeft;

	void Process();
	vec3 RandomColor();
private:	
	
	Indexs CreateIndexs();
	//Point Rotate(Point& t, float a);
	UVs GetUVs();

	UVs GetFillUVs();

	UVs GetRelaUVs();

	
};