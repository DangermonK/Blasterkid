#pragma once

#include <string>

class AudioAdapter {

public:
	AudioAdapter();
	~AudioAdapter();

	virtual void SetMusicVolume(const float& volume) = 0;
	virtual void SetSoundEffectsVolume(const float& volume) = 0;
	virtual void Play(const std::string& name) = 0;

};