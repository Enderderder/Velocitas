
// This Include
#include "RigidBody2DComponent.h"

// Engine Include
#include "GameObject.h"
#include "Debug.h"

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
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	b2Vec2 bodyPosition = b2Vec2(
		this->m_gameObject->m_transform.position.x, 
		this->m_gameObject->m_transform.position.y);
	bodyDef.position.Set(bodyPosition.x, bodyPosition.y);
	m_body = _world->CreateBody(&bodyDef);

	if (m_bHasFixture)
	{
		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(1.0f, 1.0f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;

		m_body->CreateFixture(&fixtureDef);
	}


}

