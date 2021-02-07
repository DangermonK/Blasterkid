#include "GameObject.h"

GameObject::GameObject(const Vector& position) {
	this->position = position;
}
GameObject::GameObject(const float& x, const float& y) {
	this->position = Vector(x, y);
}
GameObject::GameObject() {}

GameObject::~GameObject() {}

Vector GameObject::getPosition() {
	return position;
}
void GameObject::setPosition(const Vector& position) {
	this->position = position;
}
void GameObject::setPosition(const float& x, const float& y) {
	position = Vector(x, y);
}