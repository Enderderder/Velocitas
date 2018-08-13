//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name    : Scene.cpp
// Description	: 
// Author       : Richard Wulansari & Jacob Dewse
// Mail         : richard.wul7481@mediadesign.school.nz, jacob.dew7364@mediadesign.school.nz
//

// This Include
#include "Scene.h"

// Local Include
#include "Utility.h"
#include "GameObject.h"
//#include "Player.h"
//#include "PowerUps.h"
//#include "AssetMgr.h"
//#include "MeshMgr.h"
//#include "ModelMgr.h"
//#include "SceneMgr.h"
//#include "Input.h"
//#include "Camera.h"
//#include "CAIMgr.h"
//#include "CubeMap.h"
//#include "TextLabel.h"

// Manager Pointer
//static CAssetMgr* cAssetMgr = CAssetMgr::GetInstance();
//static CModelMgr* cModelMgr = CModelMgr::GetInstance();
//static CMeshMgr* cMeshMgr = CMeshMgr::GetInstance();

CScene::CScene()
{
	m_vGameObj.resize(0);
	m_pText.resize(0);

	m_MainCamera = nullptr;
	m_cCubeMap = nullptr;
}

// CScene::CScene(ESCENES _eSceneNum)
// {}

CScene::~CScene()
{
	std::cout << "Cleaning Scene... \n";
	// Clean up the memory allocated variables inside the class
	// ========================================================
	delete m_MainCamera;
	m_cCubeMap = nullptr;

	for (auto obj : m_vGameObj)
	{
		delete obj;
	}
	m_vGameObj.clear();

	for (auto text : m_pText)
	{
		delete text;
	}
	m_pText.clear();

	// ========================================================
	std::cout << "Cleaning Done... \n";
}

// void CScene::InitialiseScene(ESCENES _eSceneNum)
// {
// 
// }

void CScene::RenderScene()
{
	//m_cCubeMap->Render(m_MainCamera);

	for (auto obj : m_vGameObj)
	{
		obj->RenderObject(m_MainCamera);
	}
	for (unsigned int i = 0; i < m_pText.size(); i++)
	{
		//m_pText[i]->RenderTextLabel();
	}
}

void CScene::UpdateScene()
{
	//m_MainCamera->UpdateCamera();

	// Delete the object that should be deleted fron last frame
	for (auto obj : m_vGameObj)
	{
		if (obj->ShouldDestroyed()) { DestroyObject(obj); }
	}

	// Get each Object in the Scene and do their own Update Function
	size_t currVecSize = m_vGameObj.size();
	for (size_t index = 0; index < currVecSize; ++index)
	{
		m_vGameObj[index]->Update();
		currVecSize = m_vGameObj.size(); // Revalidate the number of item inside the vector
	}

	CheckCollision();
}

void CScene::CheckCollision()
{
	size_t currVecSize = m_vGameObj.size();
	for (size_t index = 0; index < currVecSize; ++index)
	{
		if (m_vGameObj[index]->HasCollider()) // Check if object itself has a collider
		{
			// Get the collistion detail of the object
			float selfCollider = m_vGameObj[index]->GetCollisionRad();
			glm::vec3 selfPos = m_vGameObj[index]->GetPosition();

			// Check with all the rest of the other objects
			for (size_t i = index + 1; i < currVecSize; ++i)
			{
				if (m_vGameObj[i]->HasCollider())
				{
					// Get the other objects' collision detail
					float otherCollider = m_vGameObj[i]->GetCollisionRad();
					glm::vec3 otherPos = m_vGameObj[i]->GetPosition();

					float distance = glm::distance(selfPos, otherPos);
					if (distance <= (selfCollider + otherCollider))
					{
						m_vGameObj[index]->OnCollision(m_vGameObj[i]);
						m_vGameObj[i]->OnCollision(m_vGameObj[index]);
					}
				}
			}
		}
		


		currVecSize = m_vGameObj.size(); // Revalidate the number of item inside the vector
	}
}

void CScene::Instantiate(CGameObject * _gameobj)
{
	m_vGameObj.push_back(_gameobj);
}

void CScene::Instantiate(CGameObject * _gameobj, glm::vec3 _pos)
{
	_gameobj->SetPosition(_pos);
	m_vGameObj.push_back(_gameobj);
}

void CScene::Instantiate(CGameObject * _gameobj, glm::vec3 _pos, glm::vec3 _scale)
{
	_gameobj->SetPosition(_pos);
	_gameobj->SetScale(_scale);
	m_vGameObj.push_back(_gameobj);
}

void CScene::Instantiate(CGameObject* _gameobj, glm::vec3 _pos, glm::vec3 _scale, glm::vec3 _rotation)
{
	_gameobj->SetPosition(_pos);
	_gameobj->SetScale(_scale);
	_gameobj->SetRotation(_rotation);
	m_vGameObj.push_back(_gameobj);
}

void CScene::DestroyObject(CGameObject* _gameobj)
{
	for (auto iter = m_vGameObj.begin(); iter != m_vGameObj.end(); ++iter)
	{
		if ((*iter) == _gameobj)
		{
			delete (*iter);
			m_vGameObj.erase(iter);
			break;
		}
	}
}

std::vector<CGameObject*> CScene::GetObjectVec() const
{
	return m_vGameObj;
}
