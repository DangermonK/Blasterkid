#include "SFML_Audio.h"

SFMLAudio::SFMLAudio() : AudioAdapter() {

	buffer1.loadFromFile("blob.wav");
	sound1.setBuffer(buffer1);

}
SFMLAudio::~SFMLAudio() {
}

void SFMLAudio::Play(const std::string& name) {
	sound1.play();
}

void SFMLAudio::SetMusicVolume(const float& volume) {
}

void SFMLAudio::SetSoundEffectsVolume(const float& volume) {

}