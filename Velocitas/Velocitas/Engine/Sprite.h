#pragma once

#include "Utility.h"
#include "Camera.h"

class Sprite
{
public:
	Sprite() =  default;
	Sprite(const char* _filePath);
	~Sprite();

	void CreateSprite(const char* _filePath);
	void RenderSprite(float _PosX, float _PosY, float _ScaleX, float _ScaleY, float _Rotation, Camera* _camera);

private:
	int m_iWidth;
	int m_iHeight;

	GLuint m_programID;
	GLuint m_vbo; // Vertex Buffer Obj
	GLuint m_vao; // Vertex Array Obj
	GLuint m_ebo; // Element Buffer Obj
	GLuint m_tex; // Texture Obj
};