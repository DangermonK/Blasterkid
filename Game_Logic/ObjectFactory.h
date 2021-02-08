#pragma once

#include "ObjectManager.h"
#include "GameObject.h"
#include "Player.h"
#include "GridMap.h"

class ObjectFactory
{

public:
	ObjectFactory(const ObjectManager& mng);
	~ObjectFactory();

	template<class T = GameObject> T* Instantiate() {
		T* obj = new T(mng, identification_counter++);
		mng.AddObject(obj);
		return obj;
	}

private:
	const ObjectManager& mng;
	unsigned int identification_counter;

};

