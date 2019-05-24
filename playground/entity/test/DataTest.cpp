#include"DataTest.h"
#include"playground/data/util/mathutil.h"
#include"playground/entity/test/util/testutil.h"
#include"playground/data/base/Matrix3x3.h"
DataTest::DataTest() {

}

bool DataTest::Run() {
	
	return true;
}

void DataTest::TestRandom() {
	for (int i = 0; i < 10; i++) {
		Print(Random());
	}
}

void DataTest::TestMatrix() {
	Matrix3x3 matrix;
	matrix.m00 = 1;
}