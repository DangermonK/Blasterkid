#pragma once

#include "GameObject.h"
#include "../Math/Rect.h"

class PhysicsObject : public GameObject {

protected:
	Rect *rect;

public:
	PhysicsObject(const unsigned int& u_id, Game* game, const Vector& position) : GameObject(u_id, game, position) {
		rect = new Rect(&this->position, Vector(10, 10));
	}
	~PhysicsObject() {}

	bool IsCollision(const PhysicsObject& other) { return rect->IsIntersecting(*other.rect); }

	virtual void OnCollision(const GameObject& collider) = 0;

};