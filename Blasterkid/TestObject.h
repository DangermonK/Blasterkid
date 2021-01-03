#pragma once

#include <iostream>
#include "GameObject.h"
#include <string>

class TestObject : public GameObject
{

public:

	TestObject(const unsigned int& u_id, Game* game, const Vector& position) : GameObject(u_id, game, position) {}
	~TestObject() {}

	void Initialize()
	{
		std::cout << "testobject " << GetId() << " wird initialisiert an position " + std::to_string(position.GetX()) + " " + std::to_string(position.GetY()) + "\n";

	}

	int i = 0;

	void Update()
	{

		i++;
		if (i > 10) {
			i = 0;
			Destroy(this);
			Instantiate(TYPE::TESTOBJECT, Vector(6, 3));
		}
		std::cout << i << " testobject " << GetId() << " wird geupdated\n";
	}

};

