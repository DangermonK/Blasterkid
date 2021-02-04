#pragma once

#include <SFML/Audio.hpp>
#include "AudioAdapter.h"

class SFMLAudio : public AudioAdapter {

public:
	SFMLAudio();
	~SFMLAudio();

	virtual void Play(const std::string& name) override;

	virtual void SetMusicVolume(const float& volume) override;

	virtual void SetSoundEffectsVolume(const float& volume) override;

private:
	sf::Music music;
	sf::Sound sound1;
	sf::Sound sound2;
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;

};