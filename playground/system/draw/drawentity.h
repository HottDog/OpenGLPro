#pragma once
#include"playground/system/core/entity.h"
using namespace OpenGL;
class DrawEntity :Entity {
public :
	virtual void Start();
	virtual void Update();
	virtual void Destroy();
};