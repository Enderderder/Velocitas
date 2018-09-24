#include "Blocks.h"

CBlocks::CBlocks(int iBlockID)
{
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigidBody2D>();
	m_iBlockID = iBlockID;
}

CBlocks::~CBlocks()
{
}

void CBlocks::BeginPlay()
{
	__super::BeginPlay();

	/** Set the sprite for the object */
	m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));
	m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));
	/** Set RigidBody */

}

void CBlocks::Update(float _tick)
{
}
