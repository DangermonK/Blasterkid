#include "Music.h"

Music::Music() : music_id(0) {}
Music::Music(const unsigned int& music_id) : music_id(music_id) {
}
Music::~Music() {}

unsigned int Music::GetMusicId() const {
	return music_id;
}