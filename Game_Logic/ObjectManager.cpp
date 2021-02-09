#include "ObjectManager.h"

ObjectManager::ObjectManager() {
	resolve = new bool();
	*resolve = false;

	obj_list = new std::list<GameObject*>();
	rem_stack = new std::stack<GameObject*>();
	add_stack = new std::stack<GameObject*>();
}
ObjectManager::~ObjectManager() {
	ResolveStack();

	delete rem_stack;
	delete add_stack;

	for (auto it = obj_list->begin(); it != obj_list->end(); it++) {
		delete *it;
	}

	delete obj_list;
}

void ObjectManager::AddObject(GameObject* obj) const {
	if (obj != nullptr) {
		*resolve = true;
		add_stack->push(obj);
	}
}
void ObjectManager::RemoveObject(GameObject* obj) const {
	if (std::find(obj_list->begin(), obj_list->end(), obj) != obj_list->end()) {
		*resolve = true;
		rem_stack->push(obj);
	}
}

void ObjectManager::Update(const AudioAdapter& audio) {
	if (*resolve) 
		ResolveStack();
	
	for (auto it = obj_list->begin(); it != obj_list->end(); it++) {
		(*it)->Update(audio);
	}
}

void ObjectManager::Render(const RenderAdapter& renderer) {
	for (auto it = obj_list->begin(); it != obj_list->end(); it++) {
		(*it)->Render(renderer);
	}
}

void ObjectManager::ResolveStack() {
	while (!rem_stack->empty()) {
		GameObject* obj = rem_stack->top();
		rem_stack->pop();

		obj_list->remove(obj);
		delete obj;
	}
	while (!add_stack->empty()) {
		obj_list->push_back(add_stack->top());
		add_stack->pop();
	}
	*resolve = false;
}
