#include "Timer.h"
Timer::Timer() {}
Timer::~Timer() {}

float Timer::delta = 0;
float Timer::last = 0;
float Timer::now = 0;
float Timer::scalar = 1;