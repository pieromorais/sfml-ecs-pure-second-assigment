#ifndef ENTITYMANAGER_HEADER_H
#define ENTITYMANAGER_HEADER_H

#include "Entity.h"
#include <cstddef>
#include <map>
#include <memory>
#include <vector>

typedef std::vector	<std::shared_ptr<Entity>>	EntityVec;
typedef std::map	<std::string, EntityVec>	EntityMap;

class EntityManager
{
private:
	EntityVec m_entities;
	EntityVec m_toAdd;
	EntityMap m_entityMap;
	size_t	  m_totalEntities = 0;
public:
	EntityManager();
	void update();
	std::shared_ptr<Entity> addEntity(const std::string& tag); // kind of entity - map
	EntityVec& getEntities();
	EntityVec& getEntities(const std::string& tag);
};

#endif
