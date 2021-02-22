#include "SFML_Audio.h"

SFMLAudio::SFMLAudio() : AudioAdapter() {}
SFMLAudio::~SFMLAudio() {
	ClearCache();
}

Sound SFMLAudio::LoadFromFile(const std::string& path) {
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	sf::Sound* sound = new sf::Sound();
	Sound s((unsigned int)std::distance(sound_map.begin(), sound_map.end()));
	buffer->loadFromFile(path);
	sound->setBuffer(*buffer);
	sound_map.push_back(sound);
	buffer_map.push_back(buffer);
	return s;
}
void SFMLAudio::ClearCache() {
	for (auto it = sound_map.begin(); it != sound_map.end(); it++) {
		(*it)->stop();
		delete* it;
	}
	for (auto it = buffer_map.begin(); it != buffer_map.end(); it++) {
		delete* it;
	}
	sound_map.clear();
	buffer_map.clear();
}

void SFMLAudio::SetMusicVolume(const float& volume) {}
void SFMLAudio::SetSoundEffectsVolume(const float& volume) {}
void SFMLAudio::Play(const Sound& sound) {
	sound_map.at(sound.GetSoundId())->play();
}