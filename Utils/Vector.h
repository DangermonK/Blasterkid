#pragma once

#include <iostream>
#include <math.h>

class Vector
{

public:
	Vector(const float& x, const float& y);
	Vector();
	~Vector();

	void Normalize();
	const Vector normalized() const;

	const float getMagnitude() const;

	void operator=(const Vector& rhs);

	void operator+=(const Vector& rhs);
	void operator-=(const Vector& rhs);

	friend Vector operator+(const Vector& lhs, const Vector& rhs) { return Vector(lhs.x + rhs.x, lhs.y + rhs.y); }
	friend Vector operator-(const Vector& lhs, const Vector& rhs) { return Vector(lhs.x - rhs.x, lhs.y - rhs.y); }

	friend Vector operator*(const Vector& lhs, const float& rhs) { return Vector(lhs.x * rhs, lhs.y * rhs); }
	friend Vector operator/(const Vector& lhs, const float& rhs) { return Vector(lhs.x / rhs, lhs.y / rhs); }
	friend Vector operator*(const float& lhs, const Vector& rhs) { return Vector(rhs.x * lhs, rhs.y * lhs); }
	friend Vector operator/(const float& lhs, const Vector& rhs) { return Vector(rhs.x / lhs, rhs.y / lhs); }

	const float getX() const;
	const float getY() const;

private:
	float x, y;

};

