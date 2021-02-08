#pragma once

#include "GameObject.h"
#include "Game.h"

class Game;
class GameObject;

class ObjectFactory
{

public:
	ObjectFactory(const Game& game);
	~ObjectFactory();

	template<class T = GameObject> T* Instantiate() {
		T* obj = new T(game, identification_counter++);
		return obj;
	}

private:
	const Game& game;
	unsigned int identification_counter;

};

