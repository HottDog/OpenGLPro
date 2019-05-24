#include"debug.h"
using namespace OpenGL;

void OpenGL::Log(char & msg)
{
	cout << "[info] " << msg << endl;
}

void OpenGL::LogError(char & error)
{
	cout << "[error] " << error << endl;
}
