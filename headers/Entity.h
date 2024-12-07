#ifndef ENTITY_HEADER_H
#define ENTITY_HEADER_H

#include "Components.h"

#include <cstddef>
#include <memory>
#include <string>



class Entity
{
private:
	// allows that only the EM create an entity
	friend class EntityManager;

	bool		m_active	= true;
	size_t		m_id		= 0;
	std::string	m_tag		= "default";

	// private constructor
	Entity(const size_t id, const std::string& tag);
public:
	// component pointers
	std::shared_ptr<CTransform>	CTransform;
	std::shared_ptr<CShape>		CShape;
	std::shared_ptr<CColision>	CColision;
	std::shared_ptr<CInput>		CInput;
	std::shared_ptr<CScore>		CScore;
	std::shared_ptr<CLifeSpan>	CLifeSpan;
	
	// private member access functions
	bool isActive() const;
	const std::string& tag() const;
	const size_t id() const;
	void destroy();
};

#endif
