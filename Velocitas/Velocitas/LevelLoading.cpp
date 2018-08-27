#include "LevelLoading.h"

// Engine Include
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRenderComponent.h"
#include <Box2D.h>
CLoadLevel::CLoadLevel()
{
	m_LevelRender = CreateComponent<CSpriteRenderComponent>();
}

CLoadLevel::~CLoadLevel()
{
}

void CLoadLevel::InitializeObject()
{
	__super::InitializeObject();
	m_LevelRender->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));
	m_LevelRender->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));

}

void CLoadLevel::Update()
{
	__super::Update();
}
