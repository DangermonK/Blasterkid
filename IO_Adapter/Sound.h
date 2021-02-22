#pragma once
class Sound
{

public:
	Sound();
	Sound(const unsigned int& sound_id);
	~Sound();

	unsigned int GetSoundId() const;

private:
	unsigned int sound_id;

};

