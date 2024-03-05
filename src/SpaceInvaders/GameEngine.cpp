#include "GameEngine.h"

GameEngine::GameEngine()
{
	m_Window = std::make_unique<RenderWindow>();
	m_ScreenManager = std::make_unique<ScreenManager>(m_Window->getResolution());
}

void GameEngine::run()
{
	while (!m_Window->shouldClose())
	{
		m_DT = m_Clock.restart();
		m_FPS = m_DT.asSeconds();

		glfwPollEvents();

		handleInput();
		update();
		draw();
	}

	glfwTerminate();
}

void GameEngine::handleInput()
{
	m_ScreenManager->handleInput(*m_Window);
}

void GameEngine::update()
{
	m_ScreenManager->update(m_FPS);
}

void GameEngine::draw()
{
	m_Window->clear();

	m_ScreenManager->draw(*m_Window);

	glfwSwapBuffers(m_Window->getGLFWwindow());
}
