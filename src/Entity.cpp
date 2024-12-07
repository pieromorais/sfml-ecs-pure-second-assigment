#include "Entity.h"
#include <cstddef>

Entity::Entity(const size_t id, const std::string& tag)
{
	this->m_id = id;
	this->m_tag = tag;
}

const std::string& Entity::tag() const
{
	return this->m_tag;
}

const size_t Entity::id() const
{
	return this->m_id;
}


bool Entity::isActive() const
{
	return this->m_active ? true : false;
}

void Entity::destroy() 
{
	// TODO:find away to destroy entity?
}

