#pragma once

// Inherited Include
#include "Component.h"

class CRigiBody2DComponent : public CComponent
{

public:

	CRigiBody2DComponent();
	~CRigiBody2DComponent();

	virtual void Update() override;
	virtual void Initialize() override;
	virtual void OnDestroy() override;

	void CreateBody(b2World* _world);

private:

	b2BodyDef m_bodyDef;
	b2Body* m_body;
};