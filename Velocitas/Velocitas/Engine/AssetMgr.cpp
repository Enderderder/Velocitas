
// This Include
#include "AssetMgr.h"

// Engine Include
#include "ShaderLoader.h"
#include "Sprite.h"
#include "Debug.h"

// Static Variable
CAssetMgr* CAssetMgr::s_pAssetMgr = nullptr;

CAssetMgr* CAssetMgr::GetInstance()
{
	if (s_pAssetMgr == nullptr)
	{
		s_pAssetMgr = new CAssetMgr();
	}

	return s_pAssetMgr;
}

void CAssetMgr::DestroyInstance()
{
	delete s_pAssetMgr;
	s_pAssetMgr = nullptr;
}

CAssetMgr::CAssetMgr() {}
CAssetMgr::~CAssetMgr() {}

void CAssetMgr::InitializeAssets()
{
	/** Initialize Programs */
	CreateProgram("DefaultSpriteProgram", "Engine/Shaders/Sprite.vs", "Engine/Shaders/Sprite.fs");

	/** Initialize Sprites */
	CreateSprite("DefaultSprite", "Resources/Sprites/DefaultSprite.png");
	CreateSprite("Triangle", "Resources/Sprites/Player2.png");
	CreateSprite("Player", "Resources/Sprites/spaceship.png");
	CreateSprite("Gate", "Resources/Sprites/gate.png");
	CreateSprite("Collectable", "Resources/Sprites/collectable.png");
	CreateSprite("Block", "Resources/Sprites/Block.png");
	CreateSprite("Block2", "Resources/Sprites/2Block.png");
	CreateSprite("Block3", "Resources/Sprites/3Block.png");
	CreateSprite("Block4", "Resources/Sprites/4Block.png");
	CreateSprite("Block5", "Resources/Sprites/5Block.png");
	CreateSprite("Block6", "Resources/Sprites/6Block.png");
	CreateSprite("Block7", "Resources/Sprites/7Block.png");
	CreateSprite("Block8", "Resources/Sprites/8Block.png");
	CreateSprite("Block9", "Resources/Sprites/9Block.png");
	CreateSprite("Block10", "Resources/Sprites/10Block.png");
	CreateSprite("Block11", "Resources/Sprites/11Block.png");


}


CSprite* CAssetMgr::GetSprite(std::string _name) const
{
	for (auto iter = m_spriteMap.begin(); iter != m_spriteMap.end(); ++iter)
	{
		if (iter->first == _name)
		{
			return iter->second;
		}
	}

	CDebug::Log("Unable to grab sprite from name.");
	return nullptr;
}

GLuint CAssetMgr::GetProgramID(std::string _name) const
{
	for (auto iter = m_programMap.begin(); iter != m_programMap.end(); ++iter)
	{
		if (iter->first == _name)
		{
			return iter->second;
		}
	}

	CDebug::Log("Unable to grab program ID from name.");
	return NULL;
}

void CAssetMgr::CreateProgram(std::string _name, const char* _vertexPath, const char* _fragmentPath)
{
	GLuint newProgram = ShaderLoader::CreateProgram(_vertexPath, _fragmentPath);

	m_programMap.insert(std::pair<std::string, GLuint>(_name, newProgram));
}

void CAssetMgr::CreateSprite(std::string _name, const char* _pathName)
{
	CSprite* newSprite = new CSprite();
	newSprite->CreateSprite(_pathName);

	m_spriteMap.insert(std::pair<std::string, CSprite*>(_name, newSprite));
}
