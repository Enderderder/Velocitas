#pragma once

// Derive Include
#include "Component.h"

// Global Include
#include "Utility.h"

// Forward Declare
class CCamera;

class CSpriteRenderComponent : public CComponent
{
public:
	CSpriteRenderComponent();
	~CSpriteRenderComponent();

	virtual void Initialize() override;

	void RenderSprite(CCamera* camera);
	
private:

	GLuint m_TextureID;
	GLuint m_programID;

};

