#include "GameEngine.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"

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
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		glfwTerminate();
		std::exit(-1);
	}

	//m_ScreenManager = unique_ptr<ScreenManager>(new ScreenManager(Vector2i(m_Resolution.x, m_Resolution.y)));
}

void GameEngine::run()
{
	const int size = 6;
	{
		// TODO remove opengl learning
		float positions[] = {
			-.5f, -.5f,
			.5f, -.5f,
			.5f, .5f,
			-.5f, .5f
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		unsigned int vao;
		GLCall(glGenVertexArrays(1, &vao));
		GLCall(glBindVertexArray(vao));

		VertexArray(va);
		VertexBuffer vb(positions, 8 * sizeof(float));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);

		ShaderProgram shader;
		shader.AddShader(GL_VERTEX_SHADER, "VertexShader.hlsl");
		shader.AddShader(GL_FRAGMENT_SHADER, "PixelShader.hlsl");
		shader.CreateShader();
		shader.Bind();

		shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
				
		va.Unbind();
		shader.Unbind();
		vb.Unbind();
		ib.Unbind();

		float r = 0;
		float increment = 0.05f;
		while (!glfwWindowShouldClose(m_Window))
		{
			//	m_DT = m_Clock.restart();
			//	m_FPS = m_DT.asSeconds();
			//	handleInput();
			//	update();
			//draw(shader, location, r);

			glClear(GL_COLOR_BUFFER_BIT);

			shader.Bind();
			shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

			va.Bind();
			ib.Bind();

			GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

			if (r > 1.0f)
			{
				increment = -0.05f;
			}
			else if (r < 0.0f)
			{
				increment = 0.05f;
			}

			r += increment;

			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}
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

void GameEngine::draw(const unsigned int& shader, const unsigned int& location, const float& r)
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shader);
	GLCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));

	//GLCall(glBindVertexArray(vao));
	//va.Bind();
	//ib.Bind();

	/* Swap front and back buffers */
	glfwSwapBuffers(m_Window);

	/* Poll for and process events */
	glfwPollEvents();

	//m_Window.clear(Color::Black);
	//m_ScreenManager->draw(m_Window);
	//m_Window.display();
}
