#include "EntityManager.h"
#include "Entity.h"
#include <memory>
#include <iostream>

EntityManager::EntityManager() {}

void EntityManager::addEntity(const std::string& tag)
{
	// insert into to_add to avoid interator invalidation
	// occurs once we remove a entity from array while looping thru
	Entity testEntity(this->m_totalEntities + 1, "notDefault");
	std::shared_ptr sharedVector = std::make_shared<Entity>(testEntity);
	this->m_totalEntities++;
	this->m_toAdd.push_back(sharedVector);
	this->m_entityMap[tag].push_back(sharedVector);


//	return e;
}

void EntityManager::update()
{
	
	for (auto& ents : this->m_toAdd)
	{
		this->m_entities.push_back(ents);
	}
	this->m_toAdd.clear();

}

const void EntityManager::getTotalEntities() const
{
	std::cout << this->m_totalEntities << std::endl;
}

EntityVec& EntityManager::getEntities()
{
	return this->m_entities;
}

EntityVec& EntityManager::getEntities(const std::string& tag) 
{
	return this->m_entityMap[tag];
}
