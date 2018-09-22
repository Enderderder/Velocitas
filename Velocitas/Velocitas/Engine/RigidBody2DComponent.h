#pragma once

// Inherited Include
#include "Component.h"
#include "Utility.h"
class CRigiBody2DComponent : public CComponent
{

public:

	CRigiBody2DComponent();
	~CRigiBody2DComponent();

	virtual void Update(float _tick) override;
	virtual void Initialize() override;
	virtual void OnDestroy() override;
	b2Body* GetBody();
	void CreateBody(b2World* _world, b2BodyType BodyType,
		bool bCanRotate = true, bool bHasFixture = true, float Density = 1.0f, float Friction = 0.3f, int fixtureType = 0);

private:

	b2Body* m_body;
	Transform m_transform;
};