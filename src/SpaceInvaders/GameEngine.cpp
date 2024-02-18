#include "GameEngine.h"
#include <Windows.h>
#include <cstdlib>

GameEngine::GameEngine()
{
	m_Resolution.x = GetSystemMetrics(SM_CXSCREEN);
	m_Resolution.y = GetSystemMetrics(SM_CYSCREEN);
	m_Window = glfwCreateWindow(m_Resolution.x, m_Resolution.y, "Space Invaders++", NULL, NULL);
	if (!m_Window)
	{
		glfwTerminate();
		std::exit(-1);
	}

	glfwMaximizeWindow(m_Window);
	glfwMakeContextCurrent(m_Window);

	//m_ScreenManager = unique_ptr<ScreenManager>(new ScreenManager(Vector2i(m_Resolution.x, m_Resolution.y)));
}

void GameEngine::run()
{
	while (!glfwWindowShouldClose(m_Window))
	{
	//	m_DT = m_Clock.restart();
	//	m_FPS = m_DT.asSeconds();
	//	handleInput();
	//	update();
		draw();
	}

	glfwTerminate();
}

void GameEngine::handleInput()
{
	//m_ScreenManager->handleInput(m_Window);
}

void GameEngine::update()
{
	//m_ScreenManager->update(m_FPS);
}

void GameEngine::draw()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2f(-.5f, -.5f);
	glVertex2f(.0f, 0.5f);
	glVertex2f(.5f, -.5f);
	glEnd();

	/* Swap front and back buffers */
	glfwSwapBuffers(m_Window);

	/* Poll for and process events */
	glfwPollEvents();

	//m_Window.clear(Color::Black);
	//m_ScreenManager->draw(m_Window);
	//m_Window.display();
}
