#ifndef COMPONENTS_HEADER
#define COMPONENTS_HEADER

// pure data components
#include "Vec2.h"
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

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

class CColision
{
public:
	float radius = 0;
	CColision(float r)
		:radius(r){};
};

class CScore
{
public:
	int score = 0;
	CScore(int s)
		:score(s){};
};

class CLifeSpan
{
public:
	int remaining = 0; // amount of lifespan remaining on the entity
	int total = 0; // the total initial amount of lifespan
	CLifeSpan(int total)
		: remaining(total), total(total){};
};

class CInput
{
public:
	bool up		= false;
	bool left	= false;
	bool down	= false;
	bool right	= false;
	bool shoot	= false;

	CInput(){};
};


#endif
