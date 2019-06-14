#pragma once
#include"playground/data/mesh/vertexs.h"
#include<iostream>
#include <iomanip>
using namespace std;
template <typename T>
void PrintVertexs(T& v,int colomn) {
	int m = 0;
	for (int i = 0; i < v.count; i++)
	{
		if (m == 0) {
			cout << "( ";
		}
		cout << setprecision(2) << v.datas[i] ;
		if (m == colomn) {
			cout << " )" << endl;
			m = 0;
		}
		else {
			cout << ",";
			m++;
		}
	}
}