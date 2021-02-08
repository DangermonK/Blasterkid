#pragma once

#include "Timer.h"
#include <iostream>

class Animation
{

public:
	Animation(const int animation[], const float& speed);
	~Animation();

	void Update();
	void Play();
	void Play(const int& offset);
	void Stop();
	void Reset();

	const int& getCurrentFrame();

private:
	const int* animation;
	const int frames;
	float current_frame;
	const float speed;
	bool play;

};

