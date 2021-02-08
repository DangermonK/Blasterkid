#pragma once

#include <ctime>

class Timer
{

public:
	static void RefreshTimer() {
		last = now;
		now = (float)std::clock();
		delta = ((now - last) / CLOCKS_PER_SEC) * scalar;
	}
	static void setTimeScalar(const float& scalar) {
		Timer::scalar = (scalar >= 0 ? scalar : 0);
	}

	static const float& getDeltaTime() { return delta; }

private:
	Timer();
	~Timer();

	static float now, last, delta, scalar;

};

