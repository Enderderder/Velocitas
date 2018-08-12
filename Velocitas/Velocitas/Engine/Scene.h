#ifndef SCENE_H
#define SCENE_H

// OpenGL Include
#include <glew.h>
#include <freeglut.h>
#include <glm.hpp>

// Library Include
#include <vector>
#include <chrono>
#include <memory>

// Forward Declaration
enum ESCENES;
class CGameObject;
class CCamera;
class CCubeMap;
class CTextLabel;

class CScene
{
public:
	CScene();
	CScene(ESCENES _eSceneNum);
	~CScene();

	virtual void InitialiseScene(ESCENES _eSceneNum);
	virtual void RenderScene();
	virtual void UpdateScene();

	void CheckCollision();

	void Instantiate(CGameObject* _gameobj);
	void Instantiate(CGameObject* _gameobj, glm::vec3 _pos);
	void Instantiate(CGameObject* _gameobj, glm::vec3 _pos, glm::vec3 _scale);
	void Instantiate(CGameObject* _gameobj, glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation);
	void DestroyObject(CGameObject* _gameobj);

	std::vector<CGameObject*> GetObjectVec() const;
	

	CTextLabel* TextTemp;
	std::vector< CTextLabel* > m_pText;

protected:
	std::string sceneName;

	CCamera* m_MainCamera;

	CCubeMap * m_cCubeMap;

	std::vector<CGameObject*> m_vGameObj;

	std::vector< std::shared_ptr<CTextLabel> > m_vTextLabel;

private:


};

#endif // !SCENE_H