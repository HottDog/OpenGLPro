#include"application.h"
using namespace OpenGL;
Application::Application() {

}

Application::~Application() {

}

bool Application::AddEntity(Entity* entity) {
	if (entity != nullptr) {
		_mEntities.push_back(entity);
	}
	return true;
}

Application* Application::GetInstance() {
	if (application == nullptr) {
		application = new Application();
	}
	return application;
}

vector<Entity*> Application::GetAllEntities() {
	return _mEntities;
}

Application* Application::application = nullptr;
