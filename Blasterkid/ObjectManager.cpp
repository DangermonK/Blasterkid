#include "ObjectManager.h"
#include "PhysicsObject.h"

ObjectManager::ObjectManager() {
}
ObjectManager::~ObjectManager() {}

template<class T = GameObject>
void ObjectManager::AddObject() {
	add_stack.push(new T());
}

void ObjectManager::RemoveObject(GameObject* obj) {
	del_stack.push(obj);
}

void ObjectManager::ResolveStack() {
	while (!del_stack.empty()) {
		GameObject* obj = del_stack.top();
		obj_map.remove(obj);
		del_stack.pop();

		PhysicsObject* phx = dynamic_cast<PhysicsObject*>(obj);
		if (phx != nullptr)
			phx_list.remove(phx);

	}

	while (!add_stack.empty()) {
		GameObject* obj = add_stack.top();
		obj_map.push_back(obj);
		add_stack.pop();

		PhysicsObject* phx = dynamic_cast<PhysicsObject*>(obj);
		if (phx != nullptr)
			phx_list.push_back(phx);

		obj->Initialize();
	}
}

void ObjectManager::PhysicsUpdate() {
	std::list<PhysicsObject*>::iterator it_y;
	for (auto it_x = phx_list.begin(); it_x != phx_list.end(); it_x++) {
		for (it_y = it_x; it_y != phx_list.end(); ++it_y) {
			if (it_x != it_y) {
				if ((*it_x)->IsCollision(**it_y)) {
					(*it_x)->OnCollision(*it_y);
				}
			}
		}
	}
}

void ObjectManager::Update() {
	for (auto it = obj_map.begin(); it != obj_map.end(); it++) {
		(*it)->Update();
	}

	PhysicsUpdate();
	ResolveStack();

}
