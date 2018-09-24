#pragma once

// Inherited Include
#include "Component.h"

class CRigidBody2D : public CComponent
{

public:

	CRigidBody2D();
	~CRigidBody2D();

	virtual void Update(float _tick) override;
	virtual void LateUpdate(float _tick) override;
	virtual void BeginPlay() override;
	virtual void Awake() override;
	virtual void OnDestroy() override;
	b2Body* GetBody();

	/// Legacy Function
	//void CreateBody(b2World* _world, b2BodyType BodyType,
	//bool bCanRotate = true, bool bHasFixture = true, float Density = 1.0f, float Friction = 0.3f, int fixtureType = 0);

	void SetBodyType(b2BodyType _bodyType);
	b2BodyType GetBodyType() const;

	void SetCanRotate(bool _b);
	bool GetCanRotate() const;

	//void SetHasFixture(bool _b);
	//bool GetHasFixture() const;

private:

	void CreateBody();

private:

	b2Body * m_body;

	// Properties that can be set either before or after the body being declared
	b2BodyType m_bodyType;
	bool m_bCanRotate;
};