#include "Sprite.h"
#include "Utility.h"

Sprite::Sprite(const char* _filePath)
{
	CreateSprite(_filePath);
}

Sprite::~Sprite()
{}

void Sprite::CreateSprite(const char* _filePath)
{
	m_programID = Util::shaderLoader.CreateProgram("Resources/Shaders/Sprite.vs", "Resources/Shaders/Sprite.fs");

	glUseProgram(m_programID);

	glGenTextures(1, &m_tex);
	glBindTexture(GL_TEXTURE_2D, m_tex);

	unsigned char* image = SOIL_load_image(
		_filePath,		// File Path
		&m_iWidth,		// Output for the image Width
		&m_iHeight,		// Output for the image Height
		0,				// Output for the number of channels
		SOIL_LOAD_RGBA	// Load RGBA values
	);

	glTexImage2D(
		GL_TEXTURE_2D,		// Type of texture
		0,					// Mipmap level, 0 for base
		GL_RGBA,			// Number of color components in texture
		m_iWidth,			// Width of the texture
		m_iHeight,			// Height of the texture
		0,					// This value must be 0
		GL_RGBA,			// Format for the pixel data
		GL_UNSIGNED_BYTE,	// Data type for the pixel data
		image				// Pointer to image data in memory
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	float halfWidth = (float)(m_iWidth / 2);
	float halfHeight = (float)(m_iHeight / 2);

	GLfloat vertices[] = {
		// Positions				   // Tex Coords
		-halfWidth,  halfHeight, 0.0f, 0.0f, 0.0f,
		 halfWidth,  halfHeight, 0.0f, 1.0f, 0.0f,
		 halfWidth, -halfHeight, 0.0f, 1.0f, 1.0f,
		-halfWidth, -halfHeight, 0.0f, 0.0f, 1.0f,
	}; // vertices to draw onto the screen

	GLuint indices[] = {
		0, 1, 2, // First Triangle
		0, 2, 3  // Second Triangle
	};

	glGenVertexArrays(1, &m_vao); // Create VAO
	glBindVertexArray(m_vao);
	glGenBuffers(1, &m_vbo); // Create VBO
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glGenBuffers(1, &m_ebo); // Create EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Enable Back Face Culling
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);

	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		5 * sizeof(GLfloat),
		(GLvoid*)0
	);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(
		1,
		2,
		GL_FLOAT,
		GL_FALSE,
		5 * sizeof(GLfloat),
		(GLvoid*)(3 * sizeof(GLfloat))
	);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Sprite::RenderSprite(float _PosX, float _PosY, float _ScaleX, float _ScaleY, float _Rotation, Camera* _camera)
{
	glUseProgram(m_programID);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_tex);
	glUniform1i(glGetUniformLocation(m_programID, "tex"), 0);

	glm::vec3 objPosition = glm::vec3(_PosX, _PosY, 0.0f);
	glm::mat4 translate = glm::translate(glm::mat4(), objPosition);
	glm::vec3 objSclae = glm::vec3(_ScaleX, _ScaleY, 1.0);
	glm::mat4 scale = glm::scale(glm::mat4(), objSclae);
	glm::vec3 rotationAxis = glm::vec3(0.0, 0.0, 1.0);
	glm::mat4 rotation = glm::rotate(glm::mat4(), glm::radians(_Rotation), rotationAxis);
	glm::mat4 model = translate * rotation * scale;
	
	glm::mat4 MVP = _camera->GetProj() * _camera->GetView() * model;

	GLint MVPLoc = glGetUniformLocation(m_programID, "MVP");
	glUniformMatrix4fv(MVPLoc, 1, GL_FALSE, glm::value_ptr(MVP));

	glBindVertexArray(m_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
	// Unbind
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}
