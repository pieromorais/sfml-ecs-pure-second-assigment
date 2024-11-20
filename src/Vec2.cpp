#include "Vec2.h"
#include <cmath>
#include <ostream>
#include <string>

Vec2::Vec2(float xin, float yin) : x(xin), y(yin) {}

bool Vec2::operator== (const Vec2& rhs) const 
{
	return (this->x == rhs.x) && (this->y == rhs.y);
}

bool Vec2::operator!= (const Vec2& rhs) const 
{
	return (this->x != rhs.x) || (this->y != rhs.y);
}

Vec2 Vec2::operator + (const Vec2& rhs) const
{
	Vec2 output(this->x+rhs.x, this->y + rhs.y);
	return output;
}

Vec2 Vec2::operator - (const Vec2& rhs) const
{
	Vec2 output(this->x - rhs.x, this->y - rhs.y);
	return output;
}

Vec2 Vec2::operator * (const Vec2& rhs) const
{
	// matrix multiplication?
	Vec2 output(0,0);
	return output;
}

Vec2 Vec2::operator / (const Vec2& rhs) const
{
	// matrix multiplication?
	Vec2 output(0,0);
	return output;
}

void Vec2::operator += (const Vec2& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
}

void Vec2::operator -= (const Vec2& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
}

void Vec2::operator *= (float val)
{
	this->x *= val;
	this->y *= val;
}

void Vec2::operator /= (float val)
{
	this->x /= val;
	this->y /= val;
}

float Vec2::dist(const Vec2& rhs) const
{
	float rs = this->x - rhs.x;
	float ls = this->y - rhs.y;

	rs = rs*rs;
	ls = ls*ls;

	return sqrtf(rs+ls);
}

// calling friend method to print vector in the (x,y) format
std::ostream& operator << (std::ostream& os, const Vec2& v)
{
	std::string res = "(" + std::to_string(v.x) + "," + std::to_string(v.y) + ")";

	os << res;

	return os;

}
