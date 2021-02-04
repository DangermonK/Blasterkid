#pragma once

#include <math.h>

class Vector {

public:
	float x;
	float y;

	Vector() {
		this->x = 0;
		this->y = 0;
	}
	Vector(const float& x, const float& y) {
		this->x = x;
		this->y = y;
	}
	~Vector() {}
	void operator+=(const Vector& v) { this->x += v.x; this->y += v.y; }
	void operator-=(const Vector& v) { this->x -= v.x; this->y -= v.y; }
	void operator/=(const float& f) { this->x *= f; this->y *= f; }
	void operator*=(const float& f) { this->x /= f; this->y /= f; }

	friend Vector operator+(const Vector& lhs, const Vector& rhs) { return Vector(lhs.x+rhs.x, lhs.y+rhs.y); }
	friend Vector operator-(const Vector& lhs, const Vector& rhs) { return Vector(lhs.x-rhs.x, lhs.y-rhs.y); }
	friend Vector operator*(const float& f, const Vector& rhs) { return Vector(f*rhs.x, f*rhs.y); }
	friend Vector operator*(const Vector& rhs, const float& f) { return Vector(f*rhs.x, f*rhs.y); }
	friend Vector operator/(const float& f, const Vector& rhs) { return Vector(rhs.x/f, rhs.y/f); }
	friend Vector operator/(const Vector& rhs, const float& f) { return Vector(rhs.x / f, rhs.y / f); }

	float GetMagnitude() {
		return sqrtf(x * x + y * y);
	}

	Vector Normalized() {
		float scalar = 1.f / GetMagnitude();
		return scalar * *this;
	}

};
