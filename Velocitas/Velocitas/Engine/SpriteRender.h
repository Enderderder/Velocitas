#pragma once

// Derive Include
#include "Component.h"

// Forward Declare
class CCamera;
class CSprite;

class CSpriteRender : public CComponent
{
public:
	CSpriteRender();
	virtual ~CSpriteRender();

	virtual void BeginPlay() override;

	void Render(CCamera* camera);

	void SetSprite(CSprite* _sprite);
	void SetSprite(std::string _name);

	void SetProgram(GLuint _programID);
	void SetProgram(std::string _name);
	CSprite* GetSprite();

private:

	CSprite* m_sprite;
	GLuint m_programID;

};

