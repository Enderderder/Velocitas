#pragma once

// Forward Declare
class CGameObject;


class CComponent
{
private:

	CGameObject* gameObject;
	bool isActive;

public:
	CComponent();
	~CComponent();

	virtual void Update() {}
	virtual void Initialize() {}
	virtual void OnDestroy() {}

	void SetActive(bool);

	CGameObject* GetGameObject() const { return gameObject; }
	bool IsActive() const { return isActive; }
};

