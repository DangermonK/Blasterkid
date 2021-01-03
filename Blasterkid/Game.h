#pragma once

class ObjectManager;
class ObjectGenerator;

#include "ObjectManager.h"
#include "ObjectGenerator.h"
#include "ObjectType.h"
#include "../Math/Vector.h"

class Game
{

private:
	ObjectManager* manager;
	ObjectGenerator* generator;

public:
	Game();
	~Game();

	void Initialize();
	void Update();

	void Destroy(GameObject* obj);
	GameObject* Instantiate(const TYPE& t, const Vector& position);

};

