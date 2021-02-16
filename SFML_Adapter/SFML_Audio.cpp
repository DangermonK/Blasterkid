#include "SFML_Audio.h"

SFMLAudio::SFMLAudio() : AudioAdapter() {

	buffer1.loadFromFile("blob.wav");
	sound1 = new sf::Sound();
	sound1->setBuffer(buffer1);
	sound1->setVolume(0);

}
SFMLAudio::~SFMLAudio() {
	delete sound1;
}

void SFMLAudio::Play(const std::string& name) const {
	sound1->play();
}

void SFMLAudio::SetMusicVolume(const float& volume) const {
}

void SFMLAudio::SetSoundEffectsVolume(const float& volume) const {

}