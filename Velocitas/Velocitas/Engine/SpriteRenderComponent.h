#pragma once

// Derive Include
#include "Component.h"

// Global Include
#include "Utility.h"

class CSpriteRenderComponent : public CComponent
{
public:
	CSpriteRenderComponent() = default;
	CSpriteRenderComponent(CGameObject* _gameObject);
	~CSpriteRenderComponent();
};

