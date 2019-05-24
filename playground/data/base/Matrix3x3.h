#pragma once
//标记是行+列
//[m00,m01,m02]
//[m10,m11,m12]
//[m20,m21,m22]
struct Matrix3x3 {	
	float m00;
	float m01;
	float m02;
	float m10;
	float m11;
	float m12;
	float m20;
	float m21;
	float m22;
public :
	Matrix3x3();
	Matrix3x3(float* values);
	void FormatPrint();
};