
// Engine Include
#include "Engine.h"

CRigidBody2D::CRigidBody2D() :
	m_bodyType(b2_dynamicBody),
	m_bCanRotate(true)
{}

CRigidBody2D::~CRigidBody2D()
{
	CSceneMgr::GetInstance()->GetRunningScene()->GetWorld()->DestroyBody(m_body);
	m_body = nullptr;
}

void CRigidBody2D::Update(float _tick)
{
	__super::Update(_tick);

	if (m_body) // If the body is created
	{
		// Get the owner gameobject
		CGameObject* owner = GetOwner();

		// Sync the transform of the object with the body right after the Box2D Step
		owner->m_transform.position =
			glm::vec3(m_body->GetPosition().x, m_body->GetPosition().y, owner->m_transform.position.z);
		owner->m_transform.rotation =
			glm::vec3(owner->m_transform.rotation.x,
				owner->m_transform.rotation.y,
				util::ToDeg(m_body->GetAngle()));
	}
}

void CRigidBody2D::LateUpdate(float _tick)
{
	__super::LateUpdate(_tick);

	if (m_body) // If the body is created
	{
		// Get the obj Transform
		Transform objTransform = GetOwner()->m_transform;

		// Convert glmVec3 to b2Vec2
		b2Vec2 bodyPosition = b2Vec2(objTransform.position.x, objTransform.position.y);
		float32 bodyRotation = (float32)util::ToRad(objTransform.rotation.z);

		// Set the body to the position and rotation
		m_body->SetTransform(bodyPosition, bodyRotation);
	}
}

void CRigidBody2D::BeginPlay()
{
	__super::BeginPlay();

	// Set the body transform to the gameobject transform at the beginning
	Transform ownerTransform = GetOwner()->m_transform;
	b2Vec2 position = b2Vec2(ownerTransform.position.x, ownerTransform.position.y);
	float32 rotationDeg = (float32)ownerTransform.rotation.z;
	m_body->SetTransform(position, util::ToRad(rotationDeg));
}

void CRigidBody2D::Awake()
{
	__super::Awake();

	// Create the body into the world
	CreateBody();
}

void CRigidBody2D::OnDestroy()
{
	__super::OnDestroy();

}

b2Body* CRigidBody2D::GetBody() const
{
	return m_body;
}

void CRigidBody2D::CreateCircleFixture(float _friction, float _density = 1.0f, bool _isSenor = false)
{
	// Define a circle shape
	b2CircleShape circleShape;
	float circleRadius;
	// Check if there is a sprite renderer component
	CSpriteRender* spriteRender = GetOwner()->GetComponent<CSpriteRender>();
	if (spriteRender != nullptr)
	{
		// Set the radius to whatever is higher
		float spriteWidth = spriteRender->GetSprite()->GetWidth();
		float spriteHeight = spriteRender->GetSprite()->GetHeight();
		if (spriteWidth >= spriteHeight)
		{
			circleRadius = spriteWidth;
			circleShape.m_radius =
				(spriteWidth * GetOwner()->m_transform.scale.x / 2.0f) / util::PIXELUNIT;
		}
		else
		{
			circleRadius = spriteHeight;
			circleShape.m_radius =
				(spriteHeight * GetOwner()->m_transform.scale.x / 2.0f) / util::PIXELUNIT;
		}
	}
	else { circleRadius = 1.0f; } // If there is no 

	
	
	
	b2FixtureDef fixtureDef;
	fixtureDef.friction = _friction;
	fixtureDef.density = _density;
	fixtureDef.isSensor = _isSenor;

	m_body->CreateFixture(&fixtureDef);
}

void CRigidBody2D::CreateBoxFixture(float _friction, float _density, bool _isSenor)
{

}

void CRigidBody2D::CreateBody()
{
	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;

	// Set the body type
	bodyDef.type = m_bodyType;

	// Set the initial transform position to the root current root position
	Transform rootTransform = GetOwner()->m_transform;
	bodyDef.position.Set(rootTransform.position.x, rootTransform.position.y);

	// Get the world of current scene and create the body in the world
	m_body = CSceneMgr::GetInstance()->GetRunningScene()->GetWorld()->CreateBody(&bodyDef);

	// Set the transform from the bodyDef to the body
	m_body->SetTransform(bodyDef.position, (util::ToRad(rootTransform.rotation.z)));

	// Set if the body can be rotate or not
	m_body->SetFixedRotation(!m_bCanRotate);

	// Set the body damping
	m_body->SetAngularDamping(0.0f);
	m_body->SetLinearDamping(0.0f);

	// At the end, Set the body component into UserData for collision listening
	m_body->SetUserData(this);
}

/// Forbbiden code
/*
void CRigiBody2D::CreateBody(b2World* _world, b2BodyType BodyType, bool bCanRotate, bool bHasFixture, float Density, float Friction, int fixtureType)
{
//m_transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
// Define the dynamic body. We set its position and call the body factory.
b2BodyDef bodyDef;
bodyDef.type = BodyType;
//bodyDef.position.Set(m_transform.position.x, m_transform.position.y);
m_body = _world->CreateBody(&bodyDef);
//m_body->SetTransform(bodyDef.position, (m_transform.direction.z / 180) * b2_pi);
m_body->SetFixedRotation(!bCanRotate);
// Define another box shape for our dynamic body.
b2PolygonShape dynamicBox;
if (GetOwner()->GetComponent<CSpriteRender>())
{
dynamicBox.SetAsBox(GetOwner()->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() / 2.0f / util::PIXELUNIT,
GetOwner()->GetComponent<CSpriteRender>()->GetSprite()->GetWidth() / 2.0f / util::PIXELUNIT);
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
*/

void CRigidBody2D::SetBodyType(b2BodyType _bodyType)
{
	m_bodyType = _bodyType;
	if (m_body)
	{
		m_body->SetType(_bodyType);
	}
}

b2BodyType CRigidBody2D::GetBodyType() const
{
	return m_bodyType;
}

void CRigidBody2D::SetCanRotate(bool _b)
{
	m_bCanRotate = _b;
	if (m_body)
	{
		m_body->SetFixedRotation(!_b);
	}
}

bool CRigidBody2D::GetCanRotate() const
{
	return m_bCanRotate;
}

/// Legacy Code
/*
void CRigiBody2D::SetHasFixture(bool _b)
{
m_bHasFixture = _b;
if (m_body)
{
if (m_body->GetFixtureList() != nullptr && _b == false)
{
m_body->DestroyFixture(m_body->GetFixtureList());
}
else if (m_body->GetFixtureList() == nullptr && _b == true)
{

}
}
}
bool CRigiBody2D::GetHasFixture() const
{
return m_bHasFixture;
}
*/