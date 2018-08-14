#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Global Includes
//#include "Utility.h"

// Forward Declare
class CGameObject;
class CComponent;
struct Trasform;

// Declare a Transform struct
struct Transform
{
	CGameObject* gameObject = nullptr;
	glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};

class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	// Properties
	std::string m_tag;
	std::string m_name;
	Transform m_transform;

protected:
	
	bool m_ShouldDestroyed;
	bool m_isActive;
	
	std::vector<CComponent*> m_components;

public:
	/*
	 * Call every frame
	 */
	virtual void Update();
	/*
	 *Check if the object should be destroyed on thie frame
	 */
	bool ShouldDestroyed() const;
	/*
	 *Destroy current gameobject and set it to inactive 
	 *of the garbage cleaning next frame
	 */
	void DestroyObject();
    /*
	 *Check if the obejct is active which determent it should update or not
	 */
	bool IsActive() const;
	/*
	 *Set active state for a object
	 */
	void SetActive(bool);

protected:
	
	/* 
	Initialize the object
	Call right after the scene initialize
	*/
	virtual void InitializeObject();
	/*
	Try get the component of the gameobject
	*/
	template<typename T>
	T* GetComponent() const;


};
#endif // !GAMEOBJECT_H