#pragma once

#include <string>
#include "Sound.h"
#include "Music.h"

class AudioAdapter {

public:
	AudioAdapter();
	virtual ~AudioAdapter();

	virtual Sound LoadSoundFromFile(const std::string& path) = 0;
	virtual Music LoadMusicFromFile(const std::string& path) = 0;
	virtual void ClearCache() = 0;

	virtual void SetMusicVolume(const float& volume) = 0;
	virtual void SetSoundVolume(const float& volume) = 0;
	virtual void Play(const Sound& a) = 0;
	virtual void Play(const Music& a) = 0;

protected:
	float soundVolume;
	float musicVolume;

};