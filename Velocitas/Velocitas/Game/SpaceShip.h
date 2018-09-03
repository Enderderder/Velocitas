#pragma once

// Derive Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRender;
class CRigiBody2D;

class CSpaceShip : public CGameObject
{
public:
	CSpaceShip(int playerID);
	~CSpaceShip();


	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;
	void MovementChecks();
	void SetIsController(bool _bIsController);
	CRigiBody2D* Get2DBody();
	CSpriteRender* m_spriteRenderer;
private:
	void Movement(bool bLeft, bool bRight, bool bUp, bool bDown);
	void RotateVecotr(b2Vec2& Vector, float fDeg);

	bool bUpPressed;
	bool bDownPressed;
	bool bLeftPressed;
	bool bRightPressed;
	CRigiBody2D* m_rigidBody;
	int m_iPlayerID;
	bool bControllerInput;
	float m_fCurrentRotation;
};

