#include "ObjectGenerator.h"


ObjectGenerator::ObjectGenerator(Game* game) {
	this->game = game;
	this->identification_counter = 0;
}
ObjectGenerator::~ObjectGenerator() {
}

GameObject* ObjectGenerator::Instantiate(const TYPE& t, const Vector& position) {
	switch (t) {
	}
	throw "ObjectGenerator::Instantiate: Type not found.";
}