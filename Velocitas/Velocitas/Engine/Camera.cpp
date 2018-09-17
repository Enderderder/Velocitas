
// This Include
#include "Camera.h"

CCamera::CCamera() :
	m_CameraPosition(glm::vec3(0.0f, 0.0f, 10.0f)),
	m_CameraFacing(glm::vec3(0.0f, 0.0f, -1.0f)),
	m_CameraNormal(glm::vec3(0.0f, 1.0f, 0.0f))
{
	CalcViewMatrix();
	SetProjectionMatrix();
}

CCamera::CCamera(glm::vec3 _Position, glm::vec3 _Facing, glm::vec3 _Normal) :
	m_CameraPosition(_Position),
	m_CameraFacing(_Facing),
	m_CameraNormal(_Normal)
{
	CalcViewMatrix();
	SetProjectionMatrix();
}

CCamera::~CCamera()
{}

void CCamera::UpdateCamera()
{

}

glm::mat4 CCamera::GetView() const
{
	return(m_ViewMatrix);
}

void CCamera::CalcViewMatrix()
{
	m_ViewMatrix = glm::lookAt(
		m_CameraPosition, 
		m_CameraPosition + m_CameraFacing,
		m_CameraNormal);
}

glm::mat4 CCamera::GetProj() const
{
	return(m_ProjectionMatrix);
}
void CCamera::SetProjectionMatrix()
{
	m_ProjectionMatrix = glm::ortho((float)-(util::SCR_WIDTH / 2), (float)(util::SCR_WIDTH / 2),
		(float)-(util::SCR_HEIGHT / 2), (float)(util::SCR_HEIGHT / 2), 0.1f, 100.0f);
}

void CCamera::SetProjectionMatrix(float _fov)
{
	m_ProjectionMatrix = glm::perspective(_fov,
		(float)util::SCR_WIDTH / (float)util::SCR_HEIGHT, 0.1f, 3000.0f);
}

glm::vec3 CCamera::GetCameraPosition() const
{
	return(m_CameraPosition);
}
void CCamera::SetCameraPosition(glm::vec3 _Position)
{
	m_CameraPosition = _Position;

	CalcViewMatrix();
	SetProjectionMatrix();
}

glm::vec3 CCamera::GetCameraFacing() const
{
	return(m_CameraFacing);
}
void CCamera::SetCameraFacing(glm::vec3 _Facing)
{
	m_CameraFacing = _Facing;

	CalcViewMatrix();
	SetProjectionMatrix();
}

glm::vec3 CCamera::GetCameraNormal() const
{
	return(m_CameraNormal);
}
void CCamera::SetCameraNormal(glm::vec3 _Normal)
{
	m_CameraNormal = _Normal;

	CalcViewMatrix();
	SetProjectionMatrix();
}