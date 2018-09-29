#pragma once

// Global Include
#include "Utility.h"

// Forward Declaration
class CContactListener;
class CGameObject;
class CCamera;
class CCubeMap;
class CTextLabel;

class CScene
{
public:
	CScene();
	virtual ~CScene();

	/**
	* Create all the gameobject and configure them here
	*/
	virtual void ConfigurateScene();
	/**
	* Calls every frame and update all the gameobject in the scene
	*/
	virtual void UpdateScene(float _tick);
	/**
	* Call after configuration
	*/
	virtual void BeginPlay();
	void RenderScene();
	void ResetScene();

	void Instantiate(CGameObject* _gameobj);
	void Instantiate(CGameObject* _gameobj, glm::vec3 _pos);
	void Instantiate(CGameObject* _gameobj, glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation);
	void DestroyObject(CGameObject* _gameobj);

	void SetWorldGravity(b2Vec2 _vector);
	b2Vec2 GetWorldGravity() const;

	void SetMainCamera(CCamera* _camera);
	CCamera* GetMainCamera() const;

	b2World* GetWorld() const;
	std::vector<CGameObject*> GetObjectVec() const;

public:

	std::string m_sceneName;

protected:

	// The Camera thats rendering the scene
	CCamera* m_mainCamera;

	CCubeMap* m_cubemap;

	std::vector<CGameObject*> m_vGameObj;

	b2Vec2 m_gravity;
	b2World* m_box2DWorld;
	CContactListener* m_contactListener;

private:

};