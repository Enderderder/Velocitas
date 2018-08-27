#pragma once

// Inherited Include
#include "Component.h"

class CRigiBody2DComponent : public CComponent
{

public:

	CRigiBody2DComponent();
	~CRigiBody2DComponent();

	virtual void Update(float _tick) override;
	virtual void Initialize() override;
	virtual void OnDestroy() override;

	void CreateBody(b2World* _world);

private:

	b2Body* m_body;

	bool m_bHasFixture;
};