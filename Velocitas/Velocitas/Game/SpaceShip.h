#pragma once

// Derive Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRenderComponent;
class CRigiBody2DComponent;

class CSpaceShip : public CGameObject
{
public:
	CSpaceShip();
	~CSpaceShip();


	virtual void InitializeObject() override;
	virtual void Update() override;

private:

	CSpriteRenderComponent* m_spriteRenderer;
	CRigiBody2DComponent* m_rigidBody;
};

