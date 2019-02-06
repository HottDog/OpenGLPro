#include"DataTest.h"
#include"playground/util/mathutil.h"
#include"playground/util/testutil.h"
DataTest::DataTest() {

}

bool DataTest::Run() {
	for (int i = 0; i < 10; i++) {
		Print(Random());
	}
	return true;
}