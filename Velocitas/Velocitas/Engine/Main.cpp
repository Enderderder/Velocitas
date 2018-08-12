


// Global Include
#include "Utility.h"
#include "SceneMgr.h"
//#include "SinglePlayerScene.h"
//#include "MeshMgr.h"
//#include "ModelMgr.h"
//#include "AssetMgr.h"
//#include "CNetworkMgr.h"
//#include "network.h"
#include "Input.h"
#include "TextLabel.h"



void InititializeProgram();
void Render();
void Update();

int main(int argc, char **argv)
{
	// Set up randon
	srand((unsigned int)time(NULL));

	// Create the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GL_MULTISAMPLE);
	glutInitWindowPosition(400, 200);

	glutInitWindowSize(util::SCR_WIDTH, util::SCR_HEIGHT);
	glutCreateWindow("Velocitas");
	glEnable(GL_MULTISAMPLE);

	// Set Clear Screen Color
	glClearColor(0.0, 1.0, 0.0, 1.0); // Make the background color GREEN

	// Initialize OpenGL Library
	glewInit();
	// Initialize the Game
	InititializeProgram();

	//register callbacks
	glutIdleFunc(Update);
	glutDisplayFunc(Render);

	glutCloseFunc([]() {
		//cInputMgr->DestroyInstance();
		//cSceneMgr->DestroyInstance();
		//cNetworkMgr->DestroyInstance();
		//CAssetMgr::GetInstance()->DestroyInstance();
		//CMeshMgr::GetInstance()->DestroyInstance();
		//CModelMgr::GetInstance()->DestroyInstance();
		//delete g_FPSLabel;
	}); // Clean up the memory when closing the program

	glutMainLoop(); // Must be called last
}

void InititializeProgram()
{
	//m_pSound.PlaySound();
	//cInputMgr->InitializeInput();
	//CAssetMgr::GetInstance()->InitializeAssets();
	//CMeshMgr::GetInstance()->InitializeMeshes();
	//CModelMgr::GetInstance()->InitializeModels();

	//Menus Initialization
	//MainMenuTracker = Play;
	//GameOverTracker = Restart;
	//MultiTracker = Host;

	//FPS counter starts at 0 when programs starts up
	//g_FPSLabel = new CTextLabel("Arial");
	//g_FPSLabel->SetPosition(glm::vec2(1305.0f, 2.0f));
	//g_FPSLabel->SetColor(glm::vec3(1.0f, 1.0f, 0.2f));

	//cSceneMgr->InitializeSceneMgr();
}

void Render()
{
	//cSceneMgr->RenderCurrentScene();

	//g_FPSLabel->RenderTextLabel();

	glutSwapBuffers();
}

void Update()
{
	// Update whats currently running
	//cSceneMgr->UpdateCurrentScene();

	// Full Screen Control
	//if (cInputMgr->g_cKeyState[(unsigned char)'f'] == INPUT_FIRST_PRESS)
	//{
	//	cInputMgr->g_cKeyState[(unsigned char)'f'] = INPUT_HOLD;
	//	glutFullScreenToggle();
	//}

	// Goes To Render
	glutPostRedisplay();
}