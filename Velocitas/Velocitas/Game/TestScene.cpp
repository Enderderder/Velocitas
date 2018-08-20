
// This Include
#include "TestScene.h"

// Inlcude the game classes
#include "Game/GameClasses.h"


void CTestScene::InitailizeScene()
{
	__super::InitailizeScene();
	
	/** Create game objects in the scenes */


	this->m_vGameObj.push_back(new CSpaceShip());

}