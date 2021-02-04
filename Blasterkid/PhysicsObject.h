#pragma once

#include "GameObject.h"
#include "../Math/Rect.h"

class PhysicsObject : public GameObject {

protected:
	Rect *rect;

public:
	PhysicsObject(Game* game, const Vector& position) : GameObject(game, position) {
		rect = new Rect(&this->position, Vector(10, 10));
	}
	~PhysicsObject() {}

	Rect GetBounds() {
		return *rect;
	}

	bool IsCollision(const PhysicsObject& other) { return rect->IsIntersecting(*other.rect); }

	virtual void OnCollision(PhysicsObject* collider) = 0;

};