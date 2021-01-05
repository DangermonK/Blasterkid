#pragma once

class GameObject;

#include <map>
#include <stack>
#include <list>
#include <vector>
#include "GameObject.h"

class ObjectManager
{

private:
	std::map<unsigned int, GameObject*> obj_map;
	std::stack<GameObject*> add_stack;
	std::stack<GameObject*> del_stack;

	void PhysicsUpdate();

public:
	ObjectManager();
	~ObjectManager();

	void AddObject(GameObject* obj);
	void RemoveObject(GameObject* obj);
	
	void ResolveStack();
	void Update();
	
	template<typename T = GameObject*>
	std::list<T*> GetObjectsOfType() {
		std::list<T*> obj_vec;
		for (auto it = obj_map.begin(); it != obj_map.end(); it++) {
			T* casted_obj = dynamic_cast<T*>(it->second);
			if (casted_obj != nullptr) {
				obj_vec.push_back(casted_obj);
			}
		}
		return obj_vec;
	}

};

