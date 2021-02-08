#include "ObjectFactory.h"

ObjectFactory::ObjectFactory(const ObjectManager& mng) : mng(mng) {
	identification_counter = 0;
}
ObjectFactory::~ObjectFactory() {}