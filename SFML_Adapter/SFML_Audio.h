#pragma once

#include <SFML/Audio.hpp>
#include "AudioAdapter.h"
#include <vector>

class SFMLAudio : public AudioAdapter {

public:
	SFMLAudio();
	~SFMLAudio();

	virtual Sound LoadFromFile(const std::string& path) override;
	virtual void ClearCache() override;

	virtual void SetMusicVolume(const float& volume) override;
	virtual void SetSoundEffectsVolume(const float& volume) override;
	virtual void Play(const Sound& sound) override;

private:
	std::vector<sf::Sound*> sound_map;
	std::vector<sf::SoundBuffer*> buffer_map;

};