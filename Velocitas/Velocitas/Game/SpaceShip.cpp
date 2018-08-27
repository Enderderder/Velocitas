
// This Include
#include "SpaceShip.h"

// Engine Include
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRenderComponent.h"
#include "Engine/RigidBody2DComponent.h"
#include "Engine/Input.h"


CSpaceShip::CSpaceShip()
{
	m_spriteRenderer = CreateComponent<CSpriteRenderComponent>();
	m_rigidBody = CreateComponent<CRigiBody2DComponent>();
}

CSpaceShip::~CSpaceShip()
{}

void CSpaceShip::InitializeObject()
{
	__super::InitializeObject();
	
	/** Set the sprite for the object */
	m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));
	m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));
	m_spriteRenderer->GetGameObject()->m_transform.position = glm::vec3(100.0f,0.0f,0.0f);
	/** Set RigidBody */
	
}

void CSpaceShip::Update(float _tick)
{
	__super::Update(_tick);
	
	//CInput::GetInstance()->g_cKeyState[]
}
