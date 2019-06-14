#pragma once
#include<map>
#include<string>
#include "common/opengltool.h"
using namespace std;
class RunTime
{
public:
	// 字体的名字为key
	static map<string, map<GLchar, Character>> fontRes;
};