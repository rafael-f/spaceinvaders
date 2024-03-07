#include "GameEngine.h"
#include "ShaderManager.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

GameEngine::GameEngine()
{
	m_Window = std::make_unique<RenderWindow>();

	ShaderManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");
	ShaderManager::LoadShader("shaders/button.vs", "shaders/button.frag", nullptr, "button");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(m_Window->getResolution().x), static_cast<float>(m_Window->getResolution().y), 0.0f, -1.0f, 1.0f);
	
	ShaderProgram spriteShader = ShaderManager::GetShader("sprite");
	spriteShader.Bind();
	spriteShader.SetUniform1i("image", 0);
	spriteShader.SetUniformMat4f("projection", projection);
	spriteShader.Unbind();

	ShaderProgram buttonShader = ShaderManager::GetShader("button");
	buttonShader.Bind();
	buttonShader.SetUniformMat4f("projection", projection);
	buttonShader.Unbind();

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
