#include "ObjectFactory.h"

ObjectFactory::ObjectFactory(const Game& game) : game(game) {
	identification_counter = 0;
}
ObjectFactory::~ObjectFactory() {}
