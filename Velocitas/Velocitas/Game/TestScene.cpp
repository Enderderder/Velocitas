
// This Include
#include "TestScene.h"

// Inlcude the game classes
#include "Game/GameClasses.h"
#include "Engine/Camera.h"


void CTestScene::InitailizeScene()
{
	__super::InitailizeScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();
	
	/** Create game objects in the scenes */

	this->m_vGameObj.push_back(new CSpaceShip());

}