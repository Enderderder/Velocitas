// This include
#include "SpriteRenderComponent.h"

// Local Include
#include "GameObject.h"

CSpriteRenderComponent::CSpriteRenderComponent() {}

CSpriteRenderComponent::~CSpriteRenderComponent() {}

void CSpriteRenderComponent::Initialize()
{
	__super::Initialize();
	
	
}

void CSpriteRenderComponent::RenderSprite(CCamera* camera)
{
	if (this->m_gameObject->IsActive() == false
		|| m_TextureID == NULL)
	{
		return;
	}


}
