#pragma once

#include "Vector.h"

class Rect {

private:
	Vector* position;
	
	Vector offset;
	Vector size;

public:
	Rect(Vector* position, const Vector& size) {
		this->position = position;
		this->size = size;
		this->offset = Vector(0, 0);
	}
	Rect(Vector* position, const Vector& size, const Vector& offset) {
		this->position = position;
		this->size = size;
		this->offset = offset;
	}
	~Rect() {}

	void SetSize(const Vector& size) { this->size = size; }
	Vector GetSize() { return this->size; }

	void SetOffset(const Vector& offset) { this->offset = offset; }
	Vector GetOffset() { return this->offset; }

	Vector GetPosition() { return Vector(position->x + offset.x, position->y + offset.y); }

	bool IsIntersecting(const Rect& other) {
		return other.position->x + other.offset.x < this->position->x + this->offset.x + this->size.x &&
			other.position->x + other.offset.x + other.size.x > this->position->x + this->offset.x &&
			other.position->y + other.offset.y < this->position->y + this->offset.y + this->size.y &&
			other.position->y + other.offset.y + other.size.y > this->position->y + this->offset.y;
	}

};