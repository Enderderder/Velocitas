#pragma once

// Inherited Include
#include "Engine\Scene.h"

// Forward Declare
class CCheckPoint;

class CRichardTest : public CScene
{
public:
	CRichardTest();
	~CRichardTest();

	virtual void ConfigurateScene() override;
	virtual void BeginPlay() override;
	virtual void UpdateScene(float _tick) override;

private:

	std::vector<CCheckPoint> m_checkPoints;

};

