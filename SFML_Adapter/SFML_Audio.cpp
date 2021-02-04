#include "SFML_Audio.h"

SFMLAudio::SFMLAudio() : AudioAdapter() {

	if (buffer1.loadFromFile("test.wav")) {
		sound1.setBuffer(buffer1);
	}

	if (buffer2.loadFromFile("test2.wav")) {
		sound2.setBuffer(buffer2);
	}

	if (!music.openFromFile("Track1.wav")) {
	}

}
SFMLAudio::~SFMLAudio() {
}

void SFMLAudio::Play(const std::string& name) {
	if (name == "car") {
		if (sound1.getStatus() == sf::Sound::Playing) {
			sound1.stop();
		}
		else {
			sound1.play();
		}
	}
	else if (name == "cry") {
		if (sound2.getStatus() == sf::Sound::Playing) {
			sound2.stop();
		}
		else {
			sound2.play();
		}
	}
	else if (name == "music") {
		music.play();
	}
}

void SFMLAudio::SetMusicVolume(const float& volume) {
	music.setVolume(volume * 100);
}

void SFMLAudio::SetSoundEffectsVolume(const float& volume) {

}