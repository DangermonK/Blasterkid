#include "GameObject.h"

GameObject::GameObject(const ObjectManager& mng, const unsigned int& u_id, const Vector& position) : mng(mng), U_ID(u_id) {
	this->position = position;
}
GameObject::GameObject(const ObjectManager& mng, const unsigned int& u_id, const float& x, const float& y) : mng(mng), U_ID(u_id) {
	this->position = Vector(x, y);
}
GameObject::GameObject(const ObjectManager& mng, const unsigned int& u_id) : mng(mng), U_ID(u_id) {}

GameObject::~GameObject() {}

void GameObject::Render(const RenderAdapter& renderer) {
	renderer.DrawBlueBox(position.getX(), position.getY());
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