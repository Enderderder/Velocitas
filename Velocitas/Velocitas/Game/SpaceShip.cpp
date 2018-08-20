
// This Include
#include "SpaceShip.h"

// Engine Include
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRenderComponent.h"


CSpaceShip::CSpaceShip()
{
	m_spriteRenderer = CreateComponent<CSpriteRenderComponent>();
	


}

CSpaceShip::~CSpaceShip()
{}

void CSpaceShip::InitializeObject()
{
	__super::InitializeObject();
	
	/** Set the sprite for the object */
	m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));
	m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));

}

void CSpaceShip::Update()
{
	__super::Update();
	

}
