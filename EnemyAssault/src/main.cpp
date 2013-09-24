#include "macros.h"
#include "SceneGraph.h"
#include "ModelFactory.h"
#include "InputHandler.h"

void Init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 1, -1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	InputHandler::GetInstance();
	ModelFactory::GetInstance()->CreatePlayer(Vector2f(0, 0));
	ModelFactory::GetInstance()->CreateTriangleEnemy(Vector2f(100, 0));
	ModelFactory::GetInstance()->CreateCircleEnemy(Vector2f(200, 0));
	ModelFactory::GetInstance()->CreateSquareEnemy(Vector2f(300, 0));
}

void Render()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	SceneGraph::GetInstance()->Render();

	glutSwapBuffers();
}

void Update()
{
	SceneGraph::GetInstance()->Update();
}

void RunMainLoop(int val)
{
	Render();
	Update();

	glutTimerFunc(FPS, RunMainLoop, val);
}

void HandleKeyPress(unsigned char key, int x, int y) 
{
	InputHandler::GetInstance()->HandleKeyPress(key, x, y);
}

void HandleKeyPressUp(unsigned char key, int x, int y)
{
	InputHandler::GetInstance()->HandleKeyPressUp(key, x, y);
}

void HandleSpecialKeyPress(int key, int x, int y)
{
	InputHandler::GetInstance()->HandleSpecialKeyPress(key, x, y);
}

void HandleSpecialKeyPressUp(int key, int x, int y)
{
	InputHandler::GetInstance()->HandleSpecialKeyPressUp(key, x, y);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);

	if(!glutCreateWindow("Enemy Assault"))
	{
		return 1;
	}

	glewInit();
	Init();

	glutTimerFunc(FPS, RunMainLoop, 0);

	glutKeyboardFunc(HandleKeyPress);
	glutKeyboardUpFunc(HandleKeyPressUp);

	glutSpecialFunc(HandleSpecialKeyPress);
	glutSpecialUpFunc(HandleSpecialKeyPressUp);
	glutIgnoreKeyRepeat(GL_TRUE);

	glutDisplayFunc(Render);

	glutMainLoop();

	return 0;
}
