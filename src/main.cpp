#include "Vec2.h"
#include "Game.h"
#include "Entity.h"
#include "EntityManager.h"
#include "DebugLog.hpp"


int main()
{
	Vec2 v1(100,100);
	Vec2 v2 = v1;
	Vec2 v3(50,50);
	Vec2 v0(0,0);
	Vec2 v_(3,4);

	Vec2 vr = v1 + v3;

//	LOG("DEBUG MODE ON");
//	LOG((v1==v2));
//	LOG((v1==v3));
//	LOG((v1!=v2));
//	LOG((v1!=v3));
//	LOG((vr));
//	LOG((v_.dist(v0)));

	v1 /= 10;
//	LOG((v1));

	EntityManager em;
//	em.addEntity("enemy");
//	em.addEntity("enemy");
//	em.getTotalEntities();
	
	Game g("../config.txt");
	g.run();
	return 0;
}
