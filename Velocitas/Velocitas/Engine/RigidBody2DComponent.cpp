
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

void CRigiBody2DComponent::Update(float _tick)
{

	if (m_body)
	{
		std::cout << m_body->GetPosition().x << " :: " << m_body->GetPosition().y << std::endl;
	}
}

void CRigiBody2DComponent::Initialize()
{

}

void CRigiBody2DComponent::OnDestroy()
{

}

b2Body * CRigiBody2DComponent::GetBody()
{
	return m_body;
}

void CRigiBody2DComponent::CreateBody(b2World* _world, b2BodyType BodyType, bool bCanRotate, bool bHasFixture, float Density, float Friction, int fixtureType)
{
	m_transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = BodyType;
	bodyDef.position.Set(m_transform.position.x, m_transform.position.y);
	m_body = _world->CreateBody(&bodyDef);
	m_body->SetTransform(bodyDef.position, (m_transform.direction.z / 180) * b2_pi);
	m_body->SetFixedRotation(!bCanRotate);
	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	if (GetOwner()->GetComponent<CSpriteRenderComponent>())
	{
		dynamicBox.SetAsBox(GetOwner()->GetComponent<CSpriteRenderComponent>()->GetSprite()->GetWidth() / 2.0f,
			GetOwner()->GetComponent<CSpriteRenderComponent>()->GetSprite()->GetWidth() / 2.0f);
		if (bHasFixture)
		{
			// Define the dynamic body fixture.
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &dynamicBox;
			// Set the box density to be non-zero, so it will be dynamic.
			fixtureDef.density = Density;
			// Override the default friction.
			fixtureDef.friction = Friction;
			if (fixtureType == 0)
			{
				//fixtureDef.filter.categoryBits = 0x0004;
				//fixtureDef.filter.maskBits = 0x0002;
				fixtureDef.filter.groupIndex = -1;
			}
			else if (fixtureType == 1)
			{
				//fixtureDef.filter.categoryBits = 0x0002;
				//fixtureDef.filter.maskBits = 0x0004;
				fixtureDef.filter.groupIndex = -2;
			}
			// Add the shape to the body.
			m_body->CreateFixture(&fixtureDef);
		}
		else
		{
			m_body->CreateFixture(&dynamicBox, 0.0f);
		}
	}
	else
	{
		if (bHasFixture)
		{
			std::cout << "No sprite component Detected in: " << GetOwner()->m_name << std::endl;
		}
	}
}

