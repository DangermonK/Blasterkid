#include "SFML_Audio.h"

SFMLAudio::SFMLAudio() : AudioAdapter() {}
SFMLAudio::~SFMLAudio() {
	ClearCache();
}

Sound SFMLAudio::LoadSoundFromFile(const std::string& path) {
	sf::SoundBuffer* buffer = new sf::SoundBuffer();
	sf::Sound* sound = new sf::Sound();
	Sound s((unsigned int)std::distance(sound_map.begin(), sound_map.end()));
	
	sound->setVolume(soundVolume);

	buffer->loadFromFile(path);
	sound->setBuffer(*buffer);
	
	sound_map.push_back(sound);
	buffer_map.push_back(buffer);
	return s;
}

Music SFMLAudio::LoadMusicFromFile(const std::string& path) {
	sf::Music* music = new sf::Music();
	Music m((unsigned int)std::distance(music_map.begin(), music_map.end()));
	
	music->setVolume(musicVolume);
	music->openFromFile(path);
	
	music_map.push_back(music);
	return m;
}

void SFMLAudio::ClearCache() {
	for (auto it = music_map.begin(); it != music_map.end(); it++) {
		(*it)->stop();
		delete* it;
	}
 	for (auto it = sound_map.begin(); it != sound_map.end(); it++) {
		(*it)->stop();
		delete* it;
	}
	for (auto it = buffer_map.begin(); it != buffer_map.end(); it++) {
		delete* it;
	}
	music_map.clear();
	sound_map.clear();
	buffer_map.clear();
}

void SFMLAudio::SetMusicVolume(const float& volume) {
	musicVolume = volume;
	for (auto it = music_map.begin(); it != music_map.end(); it++) {
		(*it)->setVolume(volume);
	}
}
void SFMLAudio::SetSoundVolume(const float& volume) {
	soundVolume = volume;
	for (auto it = sound_map.begin(); it != sound_map.end(); it++) {
		(*it)->setVolume(volume);
	}
}
void SFMLAudio::Play(const Sound& sound) {
	sound_map.at(sound.GetSoundId())->play();
}
void SFMLAudio::Play(const Music& music) {
	for (auto it = music_map.begin(); it != music_map.end(); it++) {
		(*it)->stop();
	}
	music_map.at(music.GetMusicId())->play();
}