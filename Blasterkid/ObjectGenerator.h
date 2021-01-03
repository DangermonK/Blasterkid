#pragma once

#include "GameObject.h"
#include "ObjectType.h"
#include "../Math/Vector.h"

class ObjectGenerator
{

private:
	unsigned int identification_counter;
	Game* game;

	template<class T = GameObject> GameObject* GenerateObject(const Vector& position) {
		return new T(identification_counter++, game, position);
	}

public:
	ObjectGenerator(Game* game);
	~ObjectGenerator();

	GameObject* Instantiate(const TYPE& t, const Vector& position);

};

