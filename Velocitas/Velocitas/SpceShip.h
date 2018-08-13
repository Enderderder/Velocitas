#pragma once

#include "Engine/GameObject.h"




class CSpceShip : public CGameObject
{
public:
	CSpceShip();
	~CSpceShip();


	virtual void Update() override
	{
		__super::Update();
		
	}
};

