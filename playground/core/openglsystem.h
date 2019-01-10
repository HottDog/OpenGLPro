#pragma once
#include<vector>
#include"entity.h"
#include"application.h"
#include<iostream>
#include"playground/util/debug.h"
using namespace std;
namespace OpenGL {
	class System {
	public:
		
		bool Run();
		Application * application;
		static System * GetInstance();
	private:
		System();
		bool _mEnd = true;
		static System * _mInstance;
	};
}
 