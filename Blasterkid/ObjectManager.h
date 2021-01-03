#pragma once

class GameObject;

#include <map>
#include <stack>
#include "GameObject.h"

class ObjectManager
{

private:
	std::map<unsigned int, GameObject*>* obj_list;
	std::stack<GameObject*> add_stack;
	std::stack<GameObject*> del_stack;

public:
	ObjectManager();
	~ObjectManager();

	void AddObject(GameObject* obj);
	void RemoveObject(GameObject* obj);
	GameObject* GetObject(const unsigned int& u_id);

	void Update();
};

