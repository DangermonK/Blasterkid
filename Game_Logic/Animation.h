#pragma once

#include "Texture.h"
#include "Timer.h"
#include <iostream>

class Animation
{

public:
	Animation(const Texture animation[], const float& speed);
	~Animation();

	void Update();
	void Play();
	void Play(const int& offset);
	void Stop();
	void Reset();

	const Texture& getCurrentFrame();

private:
	const Texture* animation;
	const int frames;
	float current_frame;
	const float speed;
	bool play;

};

