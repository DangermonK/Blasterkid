#pragma once

#include <string>

class AudioAdapter {

public:
	AudioAdapter();
	virtual ~AudioAdapter();

	virtual void SetMusicVolume(const float& volume) const = 0;
	virtual void SetSoundEffectsVolume(const float& volume) const = 0;
	virtual void Play(const std::string& name) const = 0;

};