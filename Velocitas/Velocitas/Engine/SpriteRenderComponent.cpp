// This include
#include "SpriteRenderComponent.h"

// Local Include
#include "GameObject.h"
#include "Sprite.h"
#include "AssetMgr.h"

CSpriteRenderComponent::CSpriteRenderComponent() 
{
	m_sprite = CAssetMgr::GetInstance()->GetSprite("DefaultSprite");
	m_programID = CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram");
}

CSpriteRenderComponent::~CSpriteRenderComponent() {}

void CSpriteRenderComponent::BeginPlay()
{
	__super::BeginPlay();
}

void CSpriteRenderComponent::Render(CCamera* _camera)
{
	if (GetOwner()->IsActive() == false
		|| m_sprite == nullptr)
	{
		return;
	}

	m_sprite->RenderSprite(GetOwner()->m_transform, 
		_camera, m_programID);
}

void CSpriteRenderComponent::SetSprite(CSprite* _sprite)
{
	m_sprite = _sprite;
}

void CSpriteRenderComponent::SetProgram(GLuint _programID)
{
	m_programID = _programID;
}

CSprite* CSpriteRenderComponent::GetSprite()
{
	if (m_sprite)
	{
		return m_sprite;
	}
	return nullptr;
}
