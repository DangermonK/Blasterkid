#pragma once

#include <math.h>

class Vector {

private:
	float x;
	float y;

public:
	Vector() {
		this->x = 0;
		this->y = 0;
	}
	Vector(const float& x, const float& y) {
		this->x = x;
		this->y = y;
	}
	~Vector() {}

	void operator=(const Vector& v) { this->x = v.x; this->y = v.y; }
	void operator+=(const Vector& v) { this->x += v.x; this->y += v.y; }
	void operator-=(const Vector& v) { this->x -= v.x; this->y -= v.y; }
	void operator/=(const float& f) { this->x *= f; this->y *= f; }
	void operator*=(const float& f) { this->x /= f; this->y /= f; }

	friend Vector operator+(const Vector& lhs, const Vector& rhs) { return Vector(lhs.x+rhs.x, lhs.y+rhs.y); }
	friend Vector operator-(const Vector& lhs, const Vector& rhs) { return Vector(lhs.x-rhs.x, lhs.y-rhs.y); }
	friend Vector operator*(const float& f, const Vector& rhs) { return Vector(f*rhs.x, f*rhs.y); }
	friend Vector operator/(const float& f, const Vector& rhs) { return Vector(rhs.x/f, rhs.y/f); }

	void SetPosition(const float& x, const float& y) {
		this->x = x;
		this->y = y;
	}

	float GetX() { return this->x; }
	float GetY() { return this->y; }

	float GetMagnitude() {
		return sqrtf(x * x + y * y);
	}

	Vector Normalized() {
		float scalar = 1.f / GetMagnitude();
		return scalar * *this;
	}

};
