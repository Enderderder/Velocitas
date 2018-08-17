#pragma once

// Derive Include
#include "Engine/GameObject.h"

// Forward Declare
class CSpriteRenderComponent;


class CSpceShip : public CGameObject
{
public:
	CSpceShip();
	~CSpceShip();


	virtual void InitializeObject() override;
	virtual void Update() override;

private:

	CSpriteRenderComponent* m_spriteRenderer;

};

