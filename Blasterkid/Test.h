#pragma once

#include <iostream>
#include "PhysicsObject.h"

class Test : public PhysicsObject {

public:
	Test(const unsigned int& u_id, Game* game, const Vector& position) : PhysicsObject(u_id, game, position) {}
	~Test() {}

	virtual void OnCollision(const GameObject& collider) override {
		std::cout << "collision\n";
	}

	virtual void Initialize() {}

	virtual void Update() {
	
	}

};