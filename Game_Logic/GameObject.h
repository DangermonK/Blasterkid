#pragma once

#include "Vector.h"
#include "ObjectManager.h"

#include "Timer.h"

#include "RenderAdapter.h"
#include "AudioAdapter.h"

#include "Game.h"

class Game;

class GameObject
{

public:
	GameObject(const Game& game, const unsigned int& u_id);
	GameObject(const Game& game, const unsigned int& u_id, const float& x, const float& y);
	GameObject(const Game& game, const unsigned int& u_id, const Vector& position);
	virtual ~GameObject();

	friend bool operator==(const GameObject& lhs, const GameObject& rhs) { return lhs.U_ID == rhs.U_ID; };

	virtual void Update(const AudioAdapter& audio) = 0;

	void SetTexture(const Texture& texture);
	Texture GetTexture();

	Vector getPosition() const;
	void setPosition(const float& x, const float& y);
	void setPosition(const Vector& position);

	void setZIndex(const int& z_index);
	int getZIndex();

protected:
	Vector position;
	const Game& game;

private:
	const unsigned int U_ID;
	int z_index;
	Texture texture;

};

