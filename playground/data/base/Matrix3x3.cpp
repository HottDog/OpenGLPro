#include"Matrix3x3.h"
#include<iostream>
using namespace std;
Matrix3x3::Matrix3x3(){}

Matrix3x3::Matrix3x3(float * value) {
	m00 = value[0];
	m01 = value[1];
	m02 = value[2];

	m10 = value[3];
	m11 = value[4];
	m12 = value[5];

	m20 = value[6];
	m21 = value[7];
	m22 = value[8];
}

void Matrix3x3::FormatPrint() {
	cout << "[" << m00 << "," << m01 << "," << m02 << "]" << endl;
	cout << "[" << m10 << "," << m11 << "," << m12 << "]" << endl;
	cout << "[" << m20 << "," << m21 << "," << m22 << "]" << endl;
}