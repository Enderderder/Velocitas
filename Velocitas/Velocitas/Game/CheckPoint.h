#pragma once

// Inherite Include
#include "Engine/GameObject.h"

// Forward Declare
class CRigiBody2D;
class CSpriteRender;
class CSpaceShip;


class CCheckPoint : public CGameObject
{
public:
	CCheckPoint();
	~CCheckPoint();

	virtual void BeginPlay() override;
	virtual void Update(float _tick) override;

	void SetCpId(int _id);
	int GetCpId() const;

private:

	/** Components */
	CRigiBody2D* m_rigidBody2D;
	CSpriteRender* m_spriteRenderer;

	/** Variables */
	int m_checkPointID;
	std::vector<CSpaceShip*> m_persuePlayer;
};