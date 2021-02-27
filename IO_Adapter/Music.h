#pragma once
class Music
{

public:
	Music();
	Music(const unsigned int& sound_id);
	~Music();

	unsigned int GetMusicId() const;

private:
	unsigned int music_id;

};
