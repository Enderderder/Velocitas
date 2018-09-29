
// Engine Include
#include "Engine.h"

// GLobal Variables
static CTime* p_Time = CTime::GetInstance();
static CInput* p_InputMgr = CInput::GetInstance();
static CSceneMgr* p_SceneMgr = CSceneMgr::GetInstance();
static CAssetMgr* p_AssetMgr = CAssetMgr::GetInstance();

// OpenGL Main Functions
void InititializeProgram();
void Render();
void Update();

int main(int argc, char **argv)
{
	// Set up random
	srand((unsigned int)time(NULL));

	// Create the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GL_MULTISAMPLE);
	glutInitWindowPosition(400, 200);

	glutInitWindowSize(util::SCR_WIDTH, util::SCR_HEIGHT);
	glutCreateWindow("Velocitas");
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	

	// Initialize OpenGL Library
	glewInit();
	// Initialize the Game
	InititializeProgram();

	//register callbacks
	glutIdleFunc(Update);
	glutDisplayFunc(Render);

	glutCloseFunc([]() {
		p_InputMgr->DestroyInstance();
		p_SceneMgr->DestroyInstance();
		p_AssetMgr->DestroyInstance();
		p_Time->DestroyInstance();
	}); // Clean up the memory when closing the program

	glutMainLoop(); // Must be called last
}

void InititializeProgram()
{
	p_Time->Initialize();
	p_AssetMgr->InitializeAssets();
	p_SceneMgr->InitializeScenes();
	p_InputMgr->InitializeInput();
}

void Render()
{
	// Set Clear Screen Color
	glClearColor(0.0, 1.0, 0.0, 1.0); // Make the background color GREEN
	p_SceneMgr->RenderCurrentScene();

	glutSwapBuffers();
}

void Update()
{
	p_Time->Update();

	// Update whats currently running
	p_InputMgr->Update(p_Time->GetTick());
	p_SceneMgr->UpdateCurrentScene(p_Time->GetTick());

	// Full Screen Control
	//if (cInputMgr->g_cKeyState[(unsigned char)'f'] == INPUT_FIRST_PRESS)
	//{
	//	cInputMgr->g_cKeyState[(unsigned char)'f'] = INPUT_HOLD;
	//	glutFullScreenToggle();
	//}

	// Goes To Render
	glutPostRedisplay();
}