#pragma once

// Global Include
#include "Utility.h"

// Forward Declare
class CGameObject;
class CComponent;

class CGameObject
{
public:
	CGameObject();
	~CGameObject();

	// Properties
	Tag m_tag;
	std::string m_name;
	Transform m_transform;

protected:

	bool m_ShouldDestroyed;
	bool m_isActive;

	std::vector<CComponent*> m_components;

public:
	/**
	* Initialize the object
	* Call right after the scene initialize
	*/
	virtual void BeginPlay();
	/*
	* Call every frame
	*/
	virtual void Update(float _tick);
	/*
	* Call every frame after the Update of all the objects
	*/
	virtual void LateUpdate(float _tick);
	/*
	* Call when the Collision happens
	*/
	virtual void OnCollisionEnter(CGameObject* _other);
	/*
	* Call when the Collision ends
	*/
	virtual void OnCollisionEnd(CGameObject* _other);

	/**
	* Creates a component and push to the vector
	*/
	template<typename T>
	T* CreateComponent();
	/**
	* Try get the component of the gameobject
	*/
	template<typename T>
	T* GetComponent() const;
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
};

/** Template function implementation */
template<typename T>
T* CGameObject::CreateComponent()
{
	CComponent* newComponent = new T();
	newComponent->SetOwner(this);
	newComponent->Awake();

	T* resultComponent = dynamic_cast<T*>(newComponent);

	if (resultComponent != nullptr)
	{
		m_components.push_back(resultComponent);
	}

	return resultComponent;
}
template<typename T>
T* CGameObject::GetComponent() const
{

	for (CComponent* iter : m_components)
	{
		T* component = dynamic_cast<T*>(iter);
		if (component != nullptr)
		{
			return component;
		}
	}

	return nullptr;
}