#include "ObjectManager.h"
#include "PhysicsObject.h"
#include <vector>

ObjectManager::ObjectManager() {}
ObjectManager::~ObjectManager() {}

void ObjectManager::AddObject(GameObject* obj) {
	add_stack.push(obj);
}

void ObjectManager::RemoveObject(GameObject* obj) {
	del_stack.push(obj);
}

void ObjectManager::ResolveStack() {
	while (!del_stack.empty()) {
		obj_map.erase(del_stack.top()->GetId());
		del_stack.pop();
	}

	while (!add_stack.empty()) {
		GameObject* obj = add_stack.top();
		add_stack.pop();
		obj_map.insert(std::pair<unsigned int, GameObject*>(obj->GetId(), obj));
		obj->Initialize();
	}
}

void ObjectManager::PhysicsUpdate() {
	auto phx_vec = GetObjectsOfType<PhysicsObject>();
	for (auto it_x = phx_vec.begin(); it_x != phx_vec.end(); it_x++) {
		for (auto it_y = phx_vec.begin(); it_y != phx_vec.end(); it_y++) {
			if (it_x != it_y) {
				if ((*it_x)->IsCollision(**it_y)) {
					(*it_x)->OnCollision(**it_y);
				}
			}
		}
	}
}

void ObjectManager::Update() {
	for (auto it = obj_map.begin(); it != obj_map.end(); it++) {
		it->second->Update();
	}

	PhysicsUpdate();
	ResolveStack();

}
