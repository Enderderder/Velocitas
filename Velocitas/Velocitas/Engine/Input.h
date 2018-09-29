#pragma once

// Global Include
#include "Utility.h"

class CInput
{

#pragma region Singleton

public:

	// Singletom Functions
	static CInput* GetInstance();
	static void DestroyInstance();

protected:
	static CInput* s_pInput;

private:

	// Make Singleton
	CInput();
	~CInput();

	// Make this Instance Non-copyable
	CInput(const CInput& _kr) = delete;
	CInput& operator= (const CInput& _kr) = delete;

#pragma endregion Singleton

public:

	// Member Functions
	void InitializeInput();

	static void InitKeyDown(unsigned char key, int x, int y);
	static void InitKeyUp(unsigned char key, int x, int y);
	static void InitMouse(int button, int glutState, int x, int y);
	static void InitMouseMotion(int x, int y);

	void Update(float _tick);
	void RefreshKeys();

private:

	void Keyboard_Down(unsigned char key, int x, int y);
	void Keyboard_Up(unsigned char key, int x, int y);
	void Mouse(int button, int glutState, int x, int y);
	void MouseMotion(int x, int y);

public: // Public Variables

	std::vector<class XBOXController*> Players;

	unsigned int g_cKeyState[255];
	unsigned int g_cMouseState[3];
	b2Vec2 g_mousePosition;

};