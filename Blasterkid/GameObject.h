#pragma once

class Game;

#include "Game.h"
#include "ObjectType.h"

#include "../Math/Vector.h"

class GameObject
{

private:
	unsigned int u_id;
	Game* game;

public:
	GameObject(const unsigned int& u_id, Game* game, const Vector& position);
	~GameObject();

	unsigned int GetId();

	virtual void Initialize() = 0;
	virtual void Update() = 0;

	Vector GetPosition();

protected:
	Vector position;

	void Destroy(GameObject* obj);
	GameObject* Instantiate(const TYPE& t, const Vector& position);

};

