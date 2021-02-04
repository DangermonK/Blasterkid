#pragma once

class Game;

#include "Game.h"
#include "ObjectType.h"

#include "../Math/Vector.h"

class GameObject
{

private:
	Game* game;

public:
	GameObject(Game* game, const Vector& position);
	~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;

	Vector GetPosition();

protected:
	Vector position;

	void Destroy(GameObject* obj);
	GameObject* Instantiate(const TYPE& t, const Vector& position);

};

