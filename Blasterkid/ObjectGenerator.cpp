#include "ObjectGenerator.h"


ObjectGenerator::ObjectGenerator(Game* game) {
	this->game = game;
	this->identification_counter = 0;
}
ObjectGenerator::~ObjectGenerator() {
}

#include "Test.h"
GameObject* ObjectGenerator::Instantiate(const TYPE& t, const Vector& position) {
	switch (t) {
	case TYPE::TEST: return GenerateObject<Test>(position); 
	default: break;
	}
	throw "ObjectGenerator::Instantiate: Type not found.";
}