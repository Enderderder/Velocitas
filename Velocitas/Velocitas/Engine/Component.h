#pragma once

// Global Include
#include "Utility.h"

// Forward Declare
class CGameObject;

class CComponent
{
public:
	CComponent();
	~CComponent();

protected:

	CGameObject* m_gameObject;
	bool m_isActive;

// Membre Funciton
public:

	void SetGameObject(CGameObject* _gameObject);
	CGameObject* GetGameObject() const;

	virtual void Update(float _tick) {}
	virtual void Initialize() {}
	virtual void OnDestroy() {}

	CGameObject* GetOwner() const;

	void SetActive(bool);
	bool IsActive() const;
};

