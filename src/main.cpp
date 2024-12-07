#include "Vec2.h"
#include "Game.h"
#include "Entity.h"
#include "EntityManager.h"
#include <iostream> // remove later

int main()
{
	Vec2 v1(100,100);
	Vec2 v2 = v1;
	Vec2 v3(50,50);
	Vec2 v0(0,0);
	Vec2 v_(3,4);

	Vec2 vr = v1 + v3;

	std::cout << (v1 == v2) << std::endl;
	std::cout << (v1 == v3) << std::endl;
	std::cout << (v1 != v3) << std::endl;
	std::cout << (v1 != v2) << std::endl;
	std::cout << vr << std::endl;
	std::cout << v_.dist(v0) << std::endl;
	v1 /= 10;
	std::cout << v1 << std::endl;

	EntityManager em;
	em.addEntity("enemy");
	em.addEntity("enemy");
	em.getTotalEntities();
	
	Game g("teste");
	g.run();
	return 0;
}
