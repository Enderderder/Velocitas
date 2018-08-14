#pragma once

// Forward Declare
class CGameObject;


class CComponent
{
public:
	CComponent() = default;
	CComponent(CGameObject* _gameObject);
	~CComponent();

	CGameObject* m_gameObject;

protected:

	bool m_isActive;

// Membre Funciton
public:

	virtual void Update() {}
	virtual void Initialize() {}
	virtual void OnDestroy() {}

	void SetActive(bool);
	bool IsActive() const;
};

