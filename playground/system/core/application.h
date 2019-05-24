#pragma once
#include<vector>
#include"entity.h"
using namespace std;
namespace OpenGL {	
	class Application {
	public:
		bool AddEntity(Entity* entity);
		static Application* GetInstance();
		vector<Entity*> GetAllEntities();
		//template<typename T>
		/*bool Register<T>(string name = nullptr) {
			T * t = new T();
			AddEntity(t);
		}*/
	private:
		Application();
		~Application();
		vector<Entity*> _mEntities;
		static Application* application;
	};
}