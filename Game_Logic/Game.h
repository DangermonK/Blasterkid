#pragma once

#include "ObjectFactory.h"
#include "ObjectManager.h"

#include "Player.h"

class Game
{
public:
	Game();
	~Game();



private:
	ObjectFactory *factory;
	ObjectManager manager;

};

