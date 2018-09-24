
// This Include
#include "ContactListener.h"

// Engine Include
#include "Engine.h"

CContactListener::CContactListener()
{}

CContactListener::~CContactListener()
{}

void CContactListener::BeginContact(b2Contact* contact)
{
	// Get the component of the 2 colliding object body
	CRigidBody2D* rigidBodyComponentA =
		static_cast<CRigidBody2D*>(contact->GetFixtureA()->GetBody()->GetUserData());
	CRigidBody2D* rigidBodyComponentB =
		static_cast<CRigidBody2D*>(contact->GetFixtureB()->GetBody()->GetUserData());

	// Call the OnCollisionEnter Function
	rigidBodyComponentA->GetOwner()->OnCollisionEnter(rigidBodyComponentB->GetOwner());
	rigidBodyComponentB->GetOwner()->OnCollisionEnter(rigidBodyComponentA->GetOwner());
}

void CContactListener::EndContact(b2Contact* contact)
{
	// Get the component of the 2 colliding object body
	CRigidBody2D* rigidBodyComponentA =
		static_cast<CRigidBody2D*>(contact->GetFixtureA()->GetBody()->GetUserData());
	CRigidBody2D* rigidBodyComponentB =
		static_cast<CRigidBody2D*>(contact->GetFixtureB()->GetBody()->GetUserData());

	// Call the OnCollisionEnd Function
	rigidBodyComponentA->GetOwner()->OnCollisionEnd(rigidBodyComponentB->GetOwner());
	rigidBodyComponentB->GetOwner()->OnCollisionEnd(rigidBodyComponentA->GetOwner());
}

void CContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	
}

void CContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	
}