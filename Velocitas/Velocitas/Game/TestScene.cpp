
// This Include
#include "TestScene.h"

// Inlcude the game classes
#include "GameClasses.h"

// Engine Include
#include "Engine/Engine.h"

void CTestScene::ConfigurateScene()
{
	__super::ConfigurateScene();

	/** Configuration */

	this->m_sceneName = "Test Scene";
	SetWorldGravity(b2Vec2(0.0f, 0.0f));

	/** Create Camera Object */

	this->m_mainCamera = new CCamera();
	
	/** Create game objects in the scenes */

	CGameObject* spaceShip = new CSpaceShip(1);
	this->m_vGameObj.push_back(spaceShip);
	spaceShip->m_name = "Space Ship";
	spaceShip->m_tag = Tag::Player;
	CSpriteRender* spriteRender = spaceShip->GetComponent<CSpriteRender>();
	spriteRender->SetSprite("Triangle");
	CRigidBody2D* rigidBody = spaceShip->GetComponent<CRigidBody2D>();
	b2PolygonShape polygonShape;
	float32 halfWidth =
		(spriteRender->GetSprite()->GetWidth() * spaceShip->m_transform.scale.x) / 2.0f / util::PIXELUNIT;
	float32 halfHeight =
		(spriteRender->GetSprite()->GetHeight() * spaceShip->m_transform.scale.y) / 2.0f / util::PIXELUNIT;
	polygonShape.SetAsBox(halfWidth, halfHeight);
	// Define the fixture using the shape
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.isSensor = false;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.1f;
	// Create the fixture in the body
	rigidBody->GetBody()->CreateFixture(&fixtureDef);

	CGameObject* spaceShip2 = new CBlocks(1);
	spaceShip2->m_name = "Block";
	spaceShip2->m_tag = Tag::Player;
	spaceShip2->m_transform.position = glm::vec3(3.0f, 3.0f, 0.0f);
	this->m_vGameObj.push_back(spaceShip2);

	spaceShip2->GetComponent<CSpriteRender>()->SetSprite("Block");
	//spaceShip->GetComponent<CRigidBody2D>()->CreateBody(GetWorld(), b2_dynamicBody, true, true, 1.0f, 0.0f, 1);
	//spaceShip2->GetComponent<CRigidBody2D>()->CreateBody(GetWorld(), b2_staticBody, true, true, 1.0f, 0.0f, 0);
}

void CTestScene::BeginPlay()
{
	__super::BeginPlay();
	

}

void CTestScene::UpdateScene(float _tick)
{
	__super::UpdateScene(_tick);


}