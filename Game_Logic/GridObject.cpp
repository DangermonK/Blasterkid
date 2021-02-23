#include "GridObject.h"

GridObject::GridObject(const Game& mng, const unsigned int& u_id) : GameObject(mng, u_id) {
	this->grid_x = this->grid_lx = 0;
	this->grid_y = this->grid_ly = 0;
}
GridObject::GridObject(const Game& mng, const unsigned int& u_id, const int& x, const int& y) : GameObject(mng, u_id, (float)x, (float)y) {
	this->grid_x = this->grid_lx = x;
	this->grid_y = this->grid_ly = y;
}

GridObject::~GridObject() { }

void GridObject::MoveUp() {
	UpdateLastPosition();
	grid_y--;
}
void GridObject::MoveDown() {
	UpdateLastPosition();
	grid_y++;
}
void GridObject::MoveLeft() {
	UpdateLastPosition();
	grid_x--;
}
void GridObject::MoveRight() {
	UpdateLastPosition();
	grid_x++;
}

void GridObject::InterpolatePosition(const float& i) {
	position = Vector(
		(float)grid_lx + (float)(grid_x - grid_lx) * i,
		(float)grid_ly + (float)(grid_y - grid_ly) * i
	);
}

void GridObject::FlipPositionToLast() {
	int nx = grid_lx;
	int ny = grid_ly;
	grid_lx = grid_x;
	grid_ly = grid_y;
	grid_x = nx;
	grid_y = ny;
}

void GridObject::ResetToLast() {
	grid_x = grid_lx;
	grid_y = grid_ly;
}
void GridObject::ResetToFirst() {
	grid_lx = grid_x;
	grid_ly = grid_y;
}

void GridObject::UpdateLastPosition() {
	position = Vector(grid_x, grid_y);
	grid_lx = grid_x;
	grid_ly = grid_y;
}

void GridObject::setPosition(const Vector& position) {
	grid_x = (int)position.getX();
	grid_y = (int)position.getY();
	ResetToFirst();
	this->position = Vector((float)grid_x, (float)grid_y);
}
void GridObject::setPosition(const float& x, const float& y) {
	grid_x = (int)x;
	grid_y = (int)y;
	ResetToFirst();
	this->position = Vector((float)grid_x, (float)grid_y);
}

const int& GridObject::getGridPositionX() { return grid_x; }
const int& GridObject::getGridPositionY() { return grid_y; }
const int& GridObject::getLastGridPositionX() { return grid_lx; }
const int& GridObject::getLastGridPositionY() { return grid_ly; }