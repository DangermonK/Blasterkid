#include "Animation.h"

Animation::Animation(const Texture animation[], const float& speed) : animation(animation), frames((int)(sizeof animation) / (int)(sizeof animation[0])), speed(speed) {
	current_frame = 0;
	play = false;
}
Animation::~Animation() {}

void Animation::Play() {
	play = true;
}
void Animation::Play(const int& offset) {
	current_frame = (offset >= 0 ? (offset < frames ? (float)offset : frames - 1) : 0);
	play = true;
}
void Animation::Stop() {
	play = false;
}
void Animation::Reset() {
	current_frame = 0;
	play = false;
}

void Animation::Update() {
	if (play) {
		current_frame += Timer::getDeltaTime() * speed;
		if (current_frame > frames) {
			current_frame = 0;
		}
	}
}

const Texture& Animation::getCurrentFrame() {
	return animation[(int)current_frame];
}