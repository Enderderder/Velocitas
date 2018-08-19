
// This Include
#include "SpceShip.h"

// Engine Include
#include "Engine/AssetMgr.h"
#include "Engine/SpriteRenderComponent.h"


CSpceShip::CSpceShip()
{
	m_spriteRenderer = CreateComponent<CSpriteRenderComponent>();
	


}

CSpceShip::~CSpceShip()
{}

void CSpceShip::InitializeObject()
{
	__super::InitializeObject();
	
	/** Set the sprite if the object */
	m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));
	m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));

}

void CSpceShip::Update()
{
	__super::Update();
	

}
