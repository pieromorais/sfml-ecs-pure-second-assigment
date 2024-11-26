#include "EntityManager.h"
#include "Entity.h"
#include <memory>
#include <iostream>

EntityManager::EntityManager() {}

void EntityManager::addEntity(const std::string& tag)
{
	// insert into to_add to avoid interator invalidation
	// occurs once we remove a entity from array while looping thru
	Entity testEntity(42);
	std::shared_ptr sharedVector = std::make_shared<Entity>(testEntity);
	this->m_totalEntities++;
	this->m_toAdd.push_back(sharedVector);
	this->m_entityMap[tag].push_back(sharedVector);

	return e;
}
