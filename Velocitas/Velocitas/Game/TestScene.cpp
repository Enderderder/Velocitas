
// This Include
#include "TestScene.h"

// Inlcude the game classes
#include "Game/GameClasses.h"
#include "Engine/Camera.h"
#include "Engine/RigidBody2D.h"
#include "Engine/SpriteRender.h"
#include "Engine/AssetMgr.h"

void CTestScene::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();
	
	/** Create game objects in the scenes */

	CGameObject* spaceShip = new CSpaceShip(1);
	spaceShip->m_name = "Space Ship";
	spaceShip->m_tag = "Player";
	this->m_vGameObj.push_back(spaceShip);

	CGameObject* spaceShip2 = new CSpaceShip(2);
	spaceShip2->m_name = "Space Ship";
	spaceShip2->m_tag = "Player";
	spaceShip2->m_transform.position = glm::vec3(100.0f, 100.0f, 0.0f);
	this->m_vGameObj.push_back(spaceShip2);

	//spaceShip2->GetComponent<CSpriteRenderComponent>()->SetSprite(CAssetMgr::GetInstance()->GetSprite("Block"));
	//spaceShip->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 1.0f, 0.0f, 1);
	//spaceShip2->GetComponent<CRigiBody2D>()->CreateBody(GetWorld(), b2_staticBody, true, true, 1.0f, 0.0f, 0);
}

void CTestScene::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);
}
