#include "GameEngine.h"
#include <Windows.h>

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
	if (!glfwInit())
	{
		return -1;
	}

	GameEngine m_GameEngine;
	m_GameEngine.run();
	return 0;
}
