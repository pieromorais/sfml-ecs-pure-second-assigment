#include "EntityManager.h"
#include <memory>

EntityManager::EntityManager() {}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	auto e = std::make_shared<Entity>(tag, this->m_totalEntities++);
	this->m_entities.push_back(e);
	this->m_entityMap[tag].push_back(e);

	return e;
}
