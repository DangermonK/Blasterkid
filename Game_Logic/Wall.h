#pragma once

#include "GameObject.h"

class Wall : public GameObject
{

public:
	Wall(const Game& game, const unsigned int& u_id);
	~Wall();

	virtual void Update(const AudioAdapter& audio) override;

};

