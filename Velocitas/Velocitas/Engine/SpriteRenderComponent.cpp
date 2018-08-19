// This include
#include "SpriteRenderComponent.h"

// Local Include
#include "GameObject.h"
#include "Sprite.h"

CSpriteRenderComponent::CSpriteRenderComponent() {}

CSpriteRenderComponent::~CSpriteRenderComponent() {}

void CSpriteRenderComponent::Initialize()
{
	__super::Initialize();
	
	
}

void CSpriteRenderComponent::RenderSprite(CCamera* _camera)
{
	if (this->m_gameObject->IsActive() == false
		|| m_sprite == nullptr)
	{
		return;
	}

	//_sprite->RenderSprite(_camera, m_programID);

}

void CSpriteRenderComponent::SetSprite(CSprite* _sprite)
{
	m_sprite = _sprite;
}

void CSpriteRenderComponent::SetProgram(GLuint _programID)
{

}
