#pragma once

class GameObject;
class PhysicsObject;

#include <map>
#include <stack>
#include <list>
#include "GameObject.h"

class ObjectManager
{

private:
	std::map<unsigned int, GameObject*> obj_map;
	std::list<PhysicsObject*> phx_list;
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

	template<>
	std::list<PhysicsObject*> GetObjectsOfType<PhysicsObject>() {
		return phx_list;
	}

	template<>
	std::list<GameObject*> GetObjectsOfType<GameObject>() {
		std::list<GameObject*> obj_vec;
		for (auto it = obj_map.begin(); it != obj_map.end(); it++) {
			obj_vec.push_back(it->second);
		}
		return obj_vec;
	}


};

