#include "Component.h"



CComponent::CComponent() {}


CComponent::~CComponent() {}

void CComponent::SetActive(bool _b)
{
	isActive = _b;
}
