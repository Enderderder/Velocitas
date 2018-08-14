// This Inlcude 
#include "Component.h"

CComponent::CComponent(CGameObject* _gameObject) 
{
	this->m_gameObject = _gameObject;
}


CComponent::~CComponent() {}

void CComponent::SetActive(bool _b)
{
	m_isActive = _b;
}

bool CComponent::IsActive() const
{
	return m_isActive;
}
