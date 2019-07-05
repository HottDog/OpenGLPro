#include"LineRaster.h"
LineRaster::~LineRaster()
{
	if (datas != nullptr)
	{
		delete datas;
		datas = nullptr;
	}
}