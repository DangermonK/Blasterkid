#include "GameObject.h"

GameObject::GameObject(const unsigned int& u_id, Game* game, const Vector& position) {
	this->u_id = u_id;
	this->game = game;
	this->position = position;
}

GameObject::~GameObject() {}

unsigned int GameObject::GetId() {
	return u_id;
}

void GameObject::Destroy(GameObject* obj) {
	game->Destroy(obj);
}

GameObject* GameObject::Instantiate(const TYPE& t, const Vector& position) {
	return game->Instantiate(t, position);
}

Vector GameObject::GetPosition() {
	return position;
}