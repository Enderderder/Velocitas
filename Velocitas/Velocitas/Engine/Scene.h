#ifndef SCENE_H
#define SCENE_H

// Global Include
#include "Utility.h"

// Forward Declaration
class CGameObject;
class CCamera;
class CCubeMap;
class CTextLabel;

class CScene
{
public:
	CScene();
	~CScene();

	virtual void InitailizeScene();
	virtual void UpdateScene(float _tick);
	void BeginPlay();
	void RenderScene();
	void ResetScene();

	//void CheckCollision();

	void Instantiate(CGameObject* _gameobj);
	void Instantiate(CGameObject* _gameobj, glm::vec3 _pos);
	void Instantiate(CGameObject* _gameobj, glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation);
	void DestroyObject(CGameObject* _gameobj);

	b2World* GetWorld() const;

	std::vector<CGameObject*> GetObjectVec() const;


public:

	std::string m_sceneName;

protected:
	
	CCamera* m_mainCamera;

	CCubeMap* m_cubemap;

	std::vector<CGameObject*> m_vGameObj;

	b2Vec2 m_gravity;
	b2World* m_box2DWorld;

private:

};

#endif // !SCENE_H