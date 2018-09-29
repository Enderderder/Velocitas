#include "Blocks.h"

CBlocks::CBlocks(int iBlockID)
{
	m_iBlockID = iBlockID;

	/** Set the sprite for the object */
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));

	m_rigidBody = CreateComponent<CRigidBody2D>();
	

}

CBlocks::~CBlocks()
{
}

void CBlocks::BeginPlay()
{
	__super::BeginPlay();


}

void CBlocks::Update(float _tick)
{

}
