#ifndef COMPONENTS_HEADER
#define COMPONENTS_HEADER

// pure data components
#include "Vec2.h"
#include<SFML/Graphics.hpp>

class CTransform
{
public:
	Vec2	pos =	{0.0, 0.0};
	Vec2	vel =	{0.0, 0.0};
	float	angle = 0.0;

	CTransform(const Vec2& p, const Vec2& v, float a)
		:pos(p)
		,vel(v)
		,angle(a)
	{}

};

class CShape
{
public:
	sf::CircleShape circle;

	CShape(float radius, int points, const sf::Color& fill, const sf::Color& outline, float thickness)
		:circle(radius, points)
		{
			circle.setFillColor(fill);
			circle.setOutlineColor(outline);
			circle.setOutlineThickness(thickness);
			circle.setOrigin(radius, radius);
		}
};

#endif
