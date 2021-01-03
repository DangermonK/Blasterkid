#include "ObjectGenerator.h"

#include "TestObject.h"

ObjectGenerator::ObjectGenerator(Game* game) {
	this->game = game;
	this->identification_counter = 0;
}
ObjectGenerator::~ObjectGenerator() {
}

GameObject* ObjectGenerator::Instantiate(const TYPE& t, const Vector& position) {
	switch (t) {
	case TYPE::TESTOBJECT: return GenerateObject<TestObject>(position);
	}
	throw "ObjectGenerator::Instantiate: Type not found.";
}