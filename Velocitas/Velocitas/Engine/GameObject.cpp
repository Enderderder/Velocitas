
// Engine Include
#include "Engine.h"

/* Legacy Render Function*/
// void CGameObject::RenderObject(CCamera* _camera)
// {
// 	glUseProgram(m_ProgramID);
// 
// 	glm::mat4 translate = glm::translate(glm::mat4(), m_Position);
// 	glm::mat4 scale = glm::scale(glm::mat4(), m_Scale);
// 	glm::mat4 rotation = glm::mat4();
// 	rotation = glm::rotate(rotation, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
// 	rotation = glm::rotate(rotation, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
// 	rotation = glm::rotate(rotation, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
// 	glm::mat4 model = translate * rotation * scale;
// 	glm::mat4 mvp = _camera->GetProjectionMatrix() *  _camera->GetViewMatrix() * model;
// 	GLint mvpLoc = glGetUniformLocation(m_ProgramID, "MVP");
// 	glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));
// 
// 	GLint modelLoc = glGetUniformLocation(m_ProgramID, "model");
// 	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
// 
// 	glm::mat3 normalMat = glm::mat3(transpose(inverse(model)));
// 	GLuint normalMatLoc = glGetUniformLocation(m_ProgramID, "normalMat");
// 	glUniformMatrix3fv(normalMatLoc, 1, GL_FALSE, glm::value_ptr(normalMat));
// 
// 	GLuint camPosLoc = glGetUniformLocation(m_ProgramID, "camPos");
// 	glUniform3fv(camPosLoc, 1, glm::value_ptr(_camera->GetCameraPosition()));
// 
// 	if (m_IsModel)
// 	{
// 		glEnable(GL_DEPTH_TEST);
// 		glEnable(GL_CULL_FACE);
// 		glCullFace(GL_BACK);
// 		glFrontFace(GL_CCW);
// 
// 		// Render the model
// 		m_ObjModel->Render(_camera, this->m_ProgramID);
// 	}
// 	else
// 	{
// 		glActiveTexture(GL_TEXTURE0);
// 		glBindTexture(GL_TEXTURE_2D, m_TextureID);
// 		glUniform1i(glGetUniformLocation(m_ProgramID, "tex"), 0);
// 
// 		// Render the mesh after everything is binded
// 		m_ObjMesh->RenderMesh();
// 	}
// 
// 	// Unbind the program after finishing 
// 	glUseProgram(0);
// }

CGameObject::CGameObject()
{
	m_name = "GameObject";
	m_tag = Tag::Default;
	m_ShouldDestroyed = false;
	m_isActive = true;
}

CGameObject::~CGameObject()
{
	for (auto component : m_components)
	{
		delete component;
		component = nullptr;
	}
}

void CGameObject::BeginPlay()
{
	for (auto iter : m_components)
	{
		iter->BeginPlay();
	}
}

void CGameObject::Update(float _tick)
{
	for (auto iter : m_components)
	{
		iter->Update(_tick);
	}
}

void CGameObject::LateUpdate(float _tick)
{
	for (auto iter : m_components)
	{
		iter->LateUpdate(_tick);
	}
}

void CGameObject::OnCollisionEnter(CGameObject* _other)
{}

void CGameObject::OnCollisionEnd(CGameObject* _other)
{}

void CGameObject::OnMouseDown()
{
	CDebug::Log("Object On Click: " + m_name);
}

void CGameObject::DestroyObject()
{
	this->m_ShouldDestroyed = true;
}

bool CGameObject::IsActive() const
{
	return m_isActive;
}

void CGameObject::SetActive(bool _b)
{
	m_isActive = _b;
}

bool CGameObject::ShouldDestroyed() const
{
	return m_ShouldDestroyed;
}