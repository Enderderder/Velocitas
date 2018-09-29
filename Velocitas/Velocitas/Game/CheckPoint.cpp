
// This Include
#include "CheckPoint.h"

// Engine Include
#include "Engine/SpriteRender.h"
#include "Engine/RigidBody2D.h"

CCheckPoint::CCheckPoint()
{
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_rigidBody2D = CreateComponent<CRigiBody2D>();
}

CCheckPoint::~CCheckPoint()
{}

void CCheckPoint::BeginPlay()
{
	__super::BeginPlay();
	

	
}

void CCheckPoint::Update(float _tick)
{
	__super::Update(_tick);
	
	

}

void CCheckPoint::SetCpId(int _id)
{
	m_checkPointID = _id;
}

int CCheckPoint::GetCpId() const
{
	return m_checkPointID;
}

