#pragma once
#include "Wall.h"
class Destructable : public Wall
{

public:
	Destructable(const Game& game, const unsigned int& u_id);
	~Destructable();

	void Destroy();

};

