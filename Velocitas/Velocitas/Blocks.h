#pragma once

#include "Engine/Utility.h"
// Derive Include
#include "Engine/GameObject.h"
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRenderComponent.h"
#include "Engine/RigidBody2DComponent.h"
#include "Engine/Input.h"
// Forward Declare
class CSpriteRenderComponent;
class CRigiBody2DComponent;

class CBlocks : public CGameObject
{
public:
	CBlocks(int iBlockID);
	~CBlocks();
	virtual void InitializeObject() override;
	virtual void Update(float _tick) override;
	CRigiBody2DComponent* Get2DBody();
	CSpriteRenderComponent* m_spriteRenderer;
private:
	CRigiBody2DComponent* m_rigidBody;
	int m_iBlockID;
	
};



