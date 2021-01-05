#include "ObjectManager.h"
#include <vector>

ObjectManager::ObjectManager() {
	obj_list = new std::map<unsigned int, GameObject*>();
}
ObjectManager::~ObjectManager() {}

void ObjectManager::AddObject(GameObject* obj) {
	add_stack.push(obj);
}

void ObjectManager::RemoveObject(GameObject* obj) {
	del_stack.push(obj);
}

GameObject* ObjectManager::GetObject(const unsigned int& u_id) {
	if(obj_list->find(u_id) != obj_list->end())
		return obj_list->at(u_id);
	throw "ObjectManager::GetObject: No object found at position.";
}

void ObjectManager::Update() {
	std::map<unsigned int, GameObject*>::iterator it;
	for (it = obj_list->begin(); it != obj_list->end(); it++) {
		it->second->Update();
	}

	while (!del_stack.empty()) {
		obj_list->erase(del_stack.top()->GetId());
		del_stack.pop();
	}

	while (!add_stack.empty()) {
		GameObject* obj = add_stack.top();
		add_stack.pop();
		obj_list->insert(std::pair<unsigned int, GameObject*>(obj->GetId(), obj));
		obj->Initialize();
	}
}
