
// This Include
#include "SpaceShip.h"

// Engine Include
#include "Engine/AssetMgr.h"
#include "Engine/Component.h"
#include "Engine/SpriteRender.h"
#include "Engine/RigidBody2D.h"
#include "Engine/Input.h"
#include "Engine/Utility.h"

CSpaceShip::CSpaceShip(int playerID)
{
	m_spriteRenderer = CreateComponent<CSpriteRender>();
	m_rigidBody = CreateComponent<CRigiBody2D>();

	m_iPlayerID = playerID;
	bControllerInput = false;
	m_fCurrentRotation = 0;
}

CSpaceShip::~CSpaceShip()
{}

void CSpaceShip::BeginPlay()
{
	__super::BeginPlay();
	
	/** Set the sprite for the object */
	//m_spriteRenderer->SetSprite(CAssetMgr::GetInstance()->GetSprite("Triangle"));
	//m_spriteRenderer->SetProgram(CAssetMgr::GetInstance()->GetProgramID("DefaultSpriteProgram"));

}

void CSpaceShip::Update(float _tick)
{
	__super::Update(_tick);

	//CInput::GetInstance()->g_cKeyState[]
	b2Body* myBody = Get2DBody()->GetBody();
	MovementChecks();
	if (myBody)
	{
		Movement(bLeftPressed, bRightPressed, bUpPressed, bDownPressed);
	}
	//Camera::GetInstance()->SetCameraPos(Position);
}

void CSpaceShip::MovementChecks()
{
	bUpPressed = false;
	bDownPressed = false;
	bLeftPressed = false;
	bRightPressed = false;

	glm::vec2 Direction = { 0, 0 };
	glm::vec2 LeftThumbStick = { CInput::GetInstance()->Players[m_iPlayerID]->GetState().Gamepad.sThumbLX , CInput::GetInstance()->Players[m_iPlayerID]->GetState().Gamepad.sThumbLY };
	if (!bControllerInput)
	{
		bLeftPressed = m_iPlayerID == 1 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'a'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'a'] == INPUT_FIRST_PRESS);
		bRightPressed = m_iPlayerID == 1 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'d'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'d'] == INPUT_FIRST_PRESS);
		bUpPressed = m_iPlayerID == 1 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'w'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'w'] == INPUT_FIRST_PRESS);
		bDownPressed = m_iPlayerID == 1 && (CInput::GetInstance()->g_cKeyState[(unsigned char)'s'] == INPUT_HOLD ||
			CInput::GetInstance()->g_cKeyState[(unsigned char)'s'] == INPUT_FIRST_PRESS);
	}
	else
	{
		bLeftPressed = (CInput::GetInstance()->Players[m_iPlayerID]->ControllerButtons[DPAD_LEFT] == INPUT_FIRST_PRESS
			|| CInput::GetInstance()->Players[m_iPlayerID]->ControllerButtons[DPAD_LEFT] == INPUT_HOLD);
		bRightPressed = (CInput::GetInstance()->Players[m_iPlayerID]->ControllerButtons[DPAD_RIGHT] == INPUT_FIRST_PRESS
			|| CInput::GetInstance()->Players[m_iPlayerID]->ControllerButtons[DPAD_RIGHT] == INPUT_HOLD);

		if (CInput::GetInstance()->Players[m_iPlayerID]->GetState().Gamepad.bRightTrigger)
		{
			bUpPressed = true;
		}
		else
		{
			bUpPressed = false;
		}
		if (CInput::GetInstance()->Players[m_iPlayerID]->GetState().Gamepad.bLeftTrigger)
		{
			bDownPressed = true;
		}
		else
		{
			bDownPressed = false;
		}
	}
}

void CSpaceShip::SetIsController(bool _bIsController)
{
	bControllerInput = _bIsController;
}

CRigiBody2D * CSpaceShip::Get2DBody()
{
	if (GetComponent<CRigiBody2D>())
	{
		return GetComponent<CRigiBody2D>();
	}
	else
	{
		return nullptr;
	}
}

void CSpaceShip::Movement(bool bLeft, bool bRight, bool bUp, bool bDown)
{
	float Right = 0;
	float up = 0;
	if (bLeft) { Right += 1.5f; };
	if (bRight) { Right -= 1.5f; };
	if (bUp) { up++; };
	if (bDown) { up -= 0.5f; };
	m_fCurrentRotation += Right;
	b2Body* myBody = Get2DBody()->GetBody();
	if (myBody)
	{
		myBody->SetTransform(myBody->GetPosition(), (m_fCurrentRotation / 180 * b2_pi));
		b2Vec2 direction = b2Vec2(0.0f, 1.0f);
		RotateVecotr(direction, m_fCurrentRotation);
		direction.Normalize();
		direction *= (float)up * 2.0f; // 10.0f;
		myBody->ApplyForceToCenter(direction, true);
		this->m_transform.position = glm::vec3(myBody->GetPosition().x, myBody->GetPosition().y, 0.0f);
		this->m_transform.rotation.z = m_fCurrentRotation;
	}
	return;
}

void CSpaceShip::RotateVecotr(b2Vec2 & Vector, float fDeg)
{
	float px = Vector.x * cosf(fDeg / 180 * b2_pi) - Vector.y * sinf(fDeg / 180 * b2_pi);
	float py = Vector.x * sinf(fDeg / 180 * b2_pi) + Vector.y * cosf(fDeg / 180 * b2_pi);
	Vector.x = px;
	Vector.y = py;
}
