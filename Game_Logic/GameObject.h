#pragma once

#include "Vector.h"

class GameObject
{

public:
	GameObject();
	GameObject(const float& x, const float& y);
	GameObject(const Vector& position);
	~GameObject();

	virtual void Update(const float& delta_time) = 0;

	Vector getPosition();
	void setPosition(const float& x, const float& y);
	void setPosition(const Vector& position);

protected:
	Vector position;

};

