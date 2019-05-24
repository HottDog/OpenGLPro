#pragma once
class Time {
public:
	void Start();
	void Update();
	double CurTime();
	double LastFrameTime();
	static Time * Instance() {
		if (_mInstance == nullptr) {
			_mInstance = new Time();
		}

		return _mInstance;
	}
	void Destroy();
private:
	Time();
	static Time * _mInstance;
	double currentTime;
	double lastFrameTime;
	double lastTime = 0;
};