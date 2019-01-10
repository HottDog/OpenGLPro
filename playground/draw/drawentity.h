#pragma once
#include"playground/core/entity.h"
using namespace OpenGL;
class DrawEntity :Entity {
public :
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
};