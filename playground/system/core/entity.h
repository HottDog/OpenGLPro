#pragma once
#include<string>
using namespace std;
namespace OpenGL {
	class Entity {
	public:
		Entity();
		Entity(string name);
		virtual ~Entity() = 0;
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void Destroy() = 0;

		string name = "";
	};
}