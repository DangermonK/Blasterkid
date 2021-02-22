#include "Sound.h"

Sound::Sound() : sound_id(0) {}
Sound::Sound(const unsigned int& sound_id) : sound_id(sound_id) {
}
Sound::~Sound() {}

unsigned int Sound::GetSoundId() const {
	return sound_id;
}