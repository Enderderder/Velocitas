
// This Include
#include "RigidBody2DComponent.h"

// Engine Include
#include "GameObject.h"
#include "Debug.h"
#include "SpriteRenderComponent.h"
#include "Sprite.h"
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

void CRigiBody2DComponent::CreateBody(b2World* _world, b2BodyType BodyType, bool bCanRotate, bool bHasFixture, float Density, float Friction, int fixtureType)
{
	b2BodyDef bodyDef;
	bodyDef.type = BodyType;
	bodyDef.position.Set(m_transform.position.x, m_transform.position.y);
	m_body = _world->CreateBody(&bodyDef);
	m_body->SetTransform(bodyDef.position, (m_transform.rotation.z / 180) * b2_pi);
	m_body->SetFixedRotation(!bCanRotate);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(GetOwner()->GetComponent<CSpriteRenderComponent>()->GetSprite()->GetWidth() / 2.0f,
		GetOwner()->GetComponent<CSpriteRenderComponent>()->GetSprite()->GetWidth() / 2.0f);



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

