
// Engine Include
#include "Engine.h"

CScene::CScene()
{
	m_mainCamera = nullptr;
	m_cubemap = nullptr;
	m_gravity = b2Vec2(0.0f, -9.81f);
	m_box2DWorld = new b2World(m_gravity);
	m_contactListener = new CContactListener();
	m_box2DWorld->SetContactListener(m_contactListener);
}

CScene::~CScene()
{
	CDebug::Log("Cleaning Scene: " + this->m_sceneName);
	// Clean up the memory allocated variables inside the class
	// ========================================================
	delete m_mainCamera;
	m_cubemap = nullptr;

	for (auto obj : m_vGameObj)
	{
		delete obj;
	}
	m_vGameObj.clear();

	delete m_box2DWorld;
	delete m_contactListener;

	// ========================================================
	CDebug::Log("Cleaning Done...");
}

void CScene::ConfigurateScene()
{
	m_vGameObj.resize(0);
}

void CScene::BeginPlay()
{
	for (auto obj : m_vGameObj)
	{
		obj->BeginPlay();
	}
}

void CScene::RenderScene()
{
	//m_cCubeMap->Render(m_MainCamera);

	if (!m_vGameObj.empty())
	{
		for (CGameObject* gameObject : m_vGameObj)
		{
			// GameObject.render()

			if (CSpriteRender* spriteRenderer
				= gameObject->GetComponent<CSpriteRender>())
			{
				spriteRenderer->Render(m_mainCamera);
				continue;
			}
		}
	}

}

void CScene::ResetScene()
{
	CDebug::Log("Resetting Scene: " + m_sceneName);

	m_cubemap = nullptr;

	m_mainCamera = nullptr;

	for (auto obj : m_vGameObj)
	{
		delete obj;
	}
	m_vGameObj.clear();
}

void CScene::UpdateScene(float _tick)
{
	// Delete the object that should be deleted fron last frame
	for (auto obj : m_vGameObj)
	{
		if (obj->ShouldDestroyed()) { DestroyObject(obj); }
	}

	// Box2D Step
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	if (_tick == 0)
	{
		m_box2DWorld->Step(timeStep, velocityIterations, positionIterations);
	}

	// Get each Object in the Scene and do their own Update Function
	size_t currVecSize = m_vGameObj.size();
	for (size_t index = 0; index < currVecSize; ++index)
	{
		m_vGameObj[index]->Update(_tick);
		currVecSize = m_vGameObj.size(); // Revalidate the number of item inside the vector
	}

	// Do the LateUpdate function after all the normal update has been done
	for (size_t index = 0; index < currVecSize; ++index)
	{
		m_vGameObj[index]->LateUpdate(_tick);
		currVecSize = m_vGameObj.size(); // Revalidate the number of item inside the vector
	}
}

/* Legacy code */
// void CScene::CheckCollision()
// {
// 	size_t currVecSize = m_vGameObj.size();
// 	for (size_t index = 0; index < currVecSize; ++index)
// 	{
// 		if (m_vGameObj[index]->HasCollider()) // Check if object itself has a collider
// 		{
// 			// Get the collistion detail of the object
// 			float selfCollider = m_vGameObj[index]->GetCollisionRad();
// 			glm::vec3 selfPos = m_vGameObj[index]->GetTransform();
// 
// 			// Check with all the rest of the other objects
// 			for (size_t i = index + 1; i < currVecSize; ++i)
// 			{
// 				if (m_vGameObj[i]->HasCollider())
// 				{
// 					// Get the other objects' collision detail
// 					float otherCollider = m_vGameObj[i]->GetCollisionRad();
// 					glm::vec3 otherPos = m_vGameObj[i]->GetTransform();
// 
// 					float distance = glm::distance(selfPos, otherPos);
// 					if (distance <= (selfCollider + otherCollider))
// 					{
// 						m_vGameObj[index]->OnCollision(m_vGameObj[i]);
// 						m_vGameObj[i]->OnCollision(m_vGameObj[index]);
// 					}
// 				}
// 			}
// 		}
// 		
// 
// 
// 		currVecSize = m_vGameObj.size(); // Revalidate the number of item inside the vector
// 	}
// }

void CScene::Instantiate(CGameObject * _gameobj)
{
	m_vGameObj.push_back(_gameobj);
	_gameobj->BeginPlay();
}

void CScene::Instantiate(CGameObject * _gameobj, glm::vec3 _pos)
{
	m_vGameObj.push_back(_gameobj);
	_gameobj->m_transform.position = _pos;
	_gameobj->BeginPlay();
}

void CScene::Instantiate(CGameObject * _gameobj,
	glm::vec3 _pos,
	glm::vec3 _rotation,
	glm::vec3 _scale = glm::vec3(1.0f, 1.0f, 1.0f))
{
	m_vGameObj.push_back(_gameobj);
	_gameobj->m_transform.position = _pos;
	_gameobj->m_transform.rotation = _rotation;
	_gameobj->m_transform.scale = _scale;
	_gameobj->BeginPlay();
}

void CScene::DestroyObject(CGameObject* _gameobj)
{
	for (auto iter = m_vGameObj.begin(); iter != m_vGameObj.end(); ++iter)
	{
		if ((*iter) == _gameobj)
		{
			delete (*iter);
			m_vGameObj.erase(iter);
			return;
		}
	}
}

void CScene::SetWorldGravity(b2Vec2 _vector)
{
	m_gravity = _vector;
	m_box2DWorld->SetGravity(_vector);
}

b2Vec2 CScene::GetWorldGravity() const
{
	return m_gravity;
}

void CScene::SetMainCamera(CCamera* _camera)
{
	m_mainCamera = _camera;
}

CCamera* CScene::GetMainCamera() const
{
	return m_mainCamera;
}

b2World* CScene::GetWorld() const
{
	return m_box2DWorld;
}

std::vector<CGameObject*> CScene::GetObjectVec() const
{
	return m_vGameObj;
}