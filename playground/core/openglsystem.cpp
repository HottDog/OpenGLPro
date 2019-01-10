#include"openglsystem.h"
using namespace OpenGL;
System::System() {
	application = Application::GetInstance();
}

bool System::Run() {
	vector<Entity *>entitis = application->GetAllEntities();
	for each (Entity * entity in entitis)
	{
		try {
			entity->Start();
		}
		catch (exception e) {
			/*if (entity != nullptr) {
				LogError( entity->name.c_str +"��Start�׶η����쳣:"+e.what());
			}
			else {
				LogError(e.what);
			}*/
			
			return false;
		}
	}

	do {
		for each (Entity * entity in entitis)
		{
			try {
				entity->Update();
			}
			catch (exception e) {
				/*if (entity != nullptr) {
					LogError(entity->name + "��Update�׶η����쳣:" + e.what);
				}
				else {
					LogError(e.what);
				}	*/			
				return false;
			}
			
		}

	} while (_mEnd);
	
	for each (Entity * entity in entitis)
	{
		try {
			entity->Destroy();
		}
		catch (exception e) {
			/*if (entity != nullptr) {
				LogError(entity->name + "��Destroy�׶η����쳣:" + e.what);
			}
			else {
				LogError(e.what);
			}*/
		}
		
	}
	return true;
}

System * System::GetInstance() {
	if (_mInstance == nullptr) {
		_mInstance = new System();
	}
	return _mInstance;
}

System* System::_mInstance = nullptr;