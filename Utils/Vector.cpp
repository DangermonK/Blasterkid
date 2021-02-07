#include "Vector.h"

Vector::Vector(const float& x, const float& y) {
	this->x = x;
	this->y = y;
}
Vector::Vector() {
	this->x = 0;
	this->y = 0;
}
Vector::~Vector() {}

void Vector::Normalize() {
	const Vector& norm = normalized();
	x = norm.x;
	y = norm.y;
}
const Vector& Vector::normalized() {
	float mag = 1 / getMagnitude();
	return Vector(x*mag, y*mag);
}

const float& Vector::getMagnitude() {
	return std::sqrtf(x*x + y*y);
}

const float& Vector::getX() { return x; }
const float& Vector::getY() { return y; }

void Vector::operator=(const Vector& rhs) { this->x = rhs.x; this->y = rhs.y; }

void Vector::operator+=(const Vector& rhs) { this->x += rhs.x; this->y += rhs.y; }
void Vector::operator-=(const Vector& rhs) { this->x -= rhs.x; this->y -= rhs.y; }
