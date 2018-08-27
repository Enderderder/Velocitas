#pragma once

// Inherited Include
#include "Component.h"
#include "Utility.h"
class CRigiBody2DComponent : public CComponent
{

public:

	CRigiBody2DComponent();
	~CRigiBody2DComponent();

	virtual void Update() override;
	virtual void Initialize() override;
	virtual void OnDestroy() override;

	void CreateBody(b2World* _world, b2BodyType BodyType, bool bCanRotate, bool bHasFixture, float Density, float Friction, int fixtureType);

private:

	b2Body* m_body;
	Transform m_transform;
	bool m_bHasFixture;
};