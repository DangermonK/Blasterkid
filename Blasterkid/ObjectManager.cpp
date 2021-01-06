#include "ObjectManager.h"
#include "PhysicsObject.h"

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
		GameObject* obj = del_stack.top();
		obj_map.erase(obj->GetId());
		del_stack.pop();

		PhysicsObject* phx = dynamic_cast<PhysicsObject*>(obj);
		if (phx != nullptr)
			phx_list.remove(phx);

	}

	while (!add_stack.empty()) {
		GameObject* obj = add_stack.top();
		obj_map.insert(std::pair<unsigned int, GameObject*>(obj->GetId(), obj));
		add_stack.pop();

		PhysicsObject* phx = dynamic_cast<PhysicsObject*>(obj);
		if (phx != nullptr)
			phx_list.push_back(phx);

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
