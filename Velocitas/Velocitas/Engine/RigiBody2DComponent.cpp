
// This Include
#include "RigiBody2DComponent.h"

CRigiBody2DComponent::CRigiBody2DComponent()
{

}

CRigiBody2DComponent::~CRigiBody2DComponent()
{

}

void CRigiBody2DComponent::Update()
{

}

void CRigiBody2DComponent::Initialize()
{

}

void CRigiBody2DComponent::OnDestroy()
{

}

void CRigiBody2DComponent::CreateBody(b2World* _world)
{
	m_body = _world->CreateBody(&m_bodyDef);
}

