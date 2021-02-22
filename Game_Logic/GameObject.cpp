#include "GameObject.h"

GameObject::GameObject(const Game& game, const unsigned int& u_id, const Vector& position) : game(game), U_ID(u_id) {
	this->position = position;
}
GameObject::GameObject(const Game& game, const unsigned int& u_id, const float& x, const float& y) : game(game), U_ID(u_id) {
	this->position = Vector(x, y);
}
GameObject::GameObject(const Game& game, const unsigned int& u_id) : game(game), U_ID(u_id) {}

GameObject::~GameObject() {}

void GameObject::SetTexture(const Texture& texture) {
	this->texture = texture;
}

Texture GameObject::GetTexture() {
	return this->texture;
}

Vector GameObject::getPosition() {
	return position;
}
void GameObject::setPosition(const Vector& position) {
	this->position = position;
}
void GameObject::setPosition(const float& x, const float& y) {
	position = Vector(x, y);
}
