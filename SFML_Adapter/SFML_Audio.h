#pragma once

#include <SFML/Audio.hpp>
#include "AudioAdapter.h"

class SFMLAudio : public AudioAdapter {

public:
	SFMLAudio();
	~SFMLAudio();

	void Play(const std::string& name) const override;

	void SetMusicVolume(const float& volume) const override;

	void SetSoundEffectsVolume(const float& volume) const override;

private:
	sf::Music music;
	sf::Sound *sound1;
	sf::Sound sound2;
	sf::SoundBuffer buffer1;
	sf::SoundBuffer buffer2;

};