#pragma once

#include <string>
#include "Sound.h"

class AudioAdapter {

public:
	AudioAdapter();
	virtual ~AudioAdapter();

	virtual Sound LoadFromFile(const std::string& path) = 0;
	virtual void ClearCache() = 0;

	virtual void SetMusicVolume(const float& volume) = 0;
	virtual void SetSoundEffectsVolume(const float& volume) = 0;
	virtual void Play(const Sound& a) = 0;

};