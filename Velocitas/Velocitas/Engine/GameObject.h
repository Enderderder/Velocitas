//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name    : GameObject.h
// Description	: 
// Author       : Richard Wulansari & Jacob Dewse
// Mail         : richard.wul7481@mediadesign.school.nz, jacob.dew7364@mediadesign.school.nz
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Global Includes
#include "Utility.h"

// Forward Declare
class GameObject;
class CCamera;
class CMesh;
class CModel;

// Declare a Transform struct
struct Transform
{
	GameObject* gameObject;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	CGameObject(CMesh* _mesh, GLuint _textureID, GLuint _programID);
	CGameObject(CModel* _model, GLuint _programID);
	virtual void RenderObject(CCamera* _camera);
	virtual void Update() {}
	virtual void OnCollision(CGameObject* _other) {}
	void DestroyObject();

	std::string GetTag() const;
	glm::vec3 GetPosition() const;
	bool ShouldDestroyed() const;

protected:
	void InitializeObject(CMesh* _mesh, GLuint _textureID, GLuint _programID);
	void InitializeObject(CModel* _model, GLuint _programID);

	glm::vec3 m_Position;
	glm::vec3 m_Scale;
	glm::vec3 m_Rotation;
	float m_ColliderRad;

	bool m_ShouldDestroyed;
	bool m_HasCollider;
	bool m_IsModel;
	
	std::string m_tag;
	std::string m_name;
	Transform m_transform;

	GLuint m_ProgramID;
	GLuint m_TextureID;

};

#endif // !GAMEOBJECT_H