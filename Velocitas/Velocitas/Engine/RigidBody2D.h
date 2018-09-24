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
	
	b2Body* GetBody() const;

	void CreateCircleFixture(float _friction, float _density, bool _isSenor);
	void CreateBoxFixture(float _friction, float _density, bool _isSenor);

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