#pragma once

// Derive Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigidBody2D;

class CSpaceShip : public CGameObject
{
public:
	CSpaceShip(int playerID);
	~CSpaceShip();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;

	void MovementChecks();
	void SetIsController(bool _bIsController);

	

private:
	void Movement(bool bLeft, bool bRight, bool bUp, bool bDown);
	void RotateVecotr(b2Vec2& Vector, float fDeg);

	bool bUpPressed;
	bool bDownPressed;
	bool bLeftPressed;
	bool bRightPressed;
	CSpriteRender* m_spriteRenderer;
	CRigidBody2D* m_rigidBody;
	int m_iPlayerID;
	bool bControllerInput;
	float m_fCurrentRotation;
};

