#include"MatrixUtil.h"
#include<iostream>
using namespace std;
Matrix3x3 Transform(Matrix3x3 matrix) {
	Matrix3x3 result;
	result.m00 = matrix.m00;
	result.m01 = matrix.m10;
	result.m02 = matrix.m20;
	result.m10 = matrix.m01;
	result.m11 = matrix.m11;
	result.m12 = matrix.m21;
	result.m20 = matrix.m02;
	result.m21 = matrix.m12;
	result.m22 = matrix.m22;
	return result;
}

void Print(Matrix3x3 matrix) {
	cout << "[" << matrix.m00 << "," << matrix.m01 << "," << matrix.m02 << "]" << endl;
	cout << "[" << matrix.m10 << "," << matrix.m11 << "," << matrix.m12 << "]" << endl;
	cout << "[" << matrix.m20 << "," << matrix.m21 << "," << matrix.m22 << "]" << endl;
}