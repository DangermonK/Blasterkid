#include "GameObject.h"

GameObject::GameObject(const Game& game, const unsigned int& u_id, const Vector& position) : game(game), U_ID(u_id) {
	this->position = position;
}
GameObject::GameObject(const Game& game, const unsigned int& u_id, const float& x, const float& y) : game(game), U_ID(u_id) {
	this->position = Vector(x, y);
	z_index = 0;
}
GameObject::GameObject(const Game& game, const unsigned int& u_id) : game(game), U_ID(u_id) {
	z_index = 0;
}

GameObject::~GameObject() {}

void GameObject::SetTexture(const Texture& texture) {
	this->texture = texture;
}

Texture GameObject::GetTexture() {
	return this->texture;
}

Vector GameObject::getPosition() const {
	return position;
}
void GameObject::setPosition(const Vector& position) {
	this->position = position;
}
void GameObject::setPosition(const float& x, const float& y) {
	position = Vector(x, y);
}

void GameObject::setZIndex(const int& z_index) {
	this->z_index = z_index;
}
int GameObject::getZIndex() { return z_index; }