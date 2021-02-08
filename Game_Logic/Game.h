#pragma once

#include "ObjectFactory.h"
#include "ObjectManager.h"

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Start();

private:
	ObjectFactory *factory;
	ObjectManager manager;

};

