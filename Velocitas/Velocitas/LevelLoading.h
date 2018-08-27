#pragma once

// Derive Include
#include "Engine/GameObject.h"
class CSpriteRenderComponent;

class CLoadLevel : public CGameObject
{
public:
	CLoadLevel();
	~CLoadLevel();

	virtual void InitializeObject() override;
	virtual void Update() override;

private:
	CSpriteRenderComponent* m_LevelRender;
};