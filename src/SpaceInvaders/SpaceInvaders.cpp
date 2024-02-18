#include "GameEngine.h"

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
