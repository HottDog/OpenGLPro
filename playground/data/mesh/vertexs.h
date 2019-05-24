#pragma once
#include<vector>
#include"point.h"
using namespace std;
struct Vertexs {
	float * datas;
	int count;
};

struct Indexs {
	unsigned int * datas;
	int count;
};

struct UVs {
	float * datas;
	int count;
};

struct Mesh {
	Vertexs vertexs;
	Indexs indexs;
	UVs uvs;
};

struct Triangle {
	Point x;
	Point y;
	Point z;
};