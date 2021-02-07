#include "GridObject.h"

GridObject::GridObject() : GameObject() {
	this->grid_x = this->grid_lx = 0;
	this->grid_y = this->grid_ly = 0;
}
GridObject::GridObject(const int& x, const int& y) : GameObject(x, y) {
	this->grid_x = this->grid_lx = x;
	this->grid_y = this->grid_ly = y;
}

GridObject::~GridObject() {}

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

void GridObject::UpdateLastPosition() {
	grid_lx = grid_x;
	grid_ly = grid_y;
}

const int& GridObject::getGridPositionX() { return grid_x; }
const int& GridObject::getGridPositionY() { return grid_y; }
const int& GridObject::getLastGridPositionX() { return grid_lx; }
const int& GridObject::getLastGridPositionY() { return grid_ly; }