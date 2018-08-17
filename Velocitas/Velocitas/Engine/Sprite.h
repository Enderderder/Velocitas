#pragma once

// Global Include
#include "Utility.h"

// Forward Declare
struct Transform;
class CCamera;

class CSprite
{
public:
	CSprite() =  default;
	CSprite(const char* _filePath);
	~CSprite();

	void CreateSprite(const char* _filePath, GLuint _programID);
	void RenderSprite(Transform _transform, CCamera* _camera, GLuint _programID);

private:
	int m_iWidth;
	int m_iHeight;

	GLuint m_vbo; // Vertex Buffer Obj
	GLuint m_vao; // Vertex Array Obj
	GLuint m_ebo; // Element Buffer Obj
	GLuint m_tex; // Texture Obj
};