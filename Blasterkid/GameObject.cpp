#include "GameObject.h"

GameObject::GameObject(Game* game, const Vector& position) {
	this->game = game;
	this->position = position;
}

GameObject::~GameObject() {}

void GameObject::Destroy(GameObject* obj) {
	game->Destroy(obj);
}

GameObject* GameObject::Instantiate(const TYPE& t, const Vector& position) {
	return game->Instantiate(t, position);
}

Vector GameObject::GetPosition() {
	return position;
}