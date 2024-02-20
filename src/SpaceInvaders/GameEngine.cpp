#include "GameEngine.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		// todo print error
		glDeleteShader(id);
		return 0;
	}

	return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

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

std::string ReadFile(const std::string& fileName)
{
	std::ifstream file_stream(fileName);
	if (file_stream.is_open())
	{
		std::string file_content;

		std::string line;
		while (std::getline(file_stream, line)) {
			file_content += line + "\n";
		}

		file_stream.close();

		return file_content;
	}
	else
	{
		return 0;
	}
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

		std::string vertexShader = ReadFile("VertexShader.hlsl");
		std::string fragmentShader = ReadFile("PixelShader.hlsl");
		unsigned int shader = CreateShader(vertexShader, fragmentShader);
		GLCall(glUseProgram(shader));

		GLCall(int location = glGetUniformLocation(shader, "u_Color"));
		ASSERT(location != -1);
		GLCall(glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f));
		
		GLCall(glBindVertexArray(0));
		GLCall(glUseProgram(0));
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

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

			glUseProgram(shader);
			GLCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));

			GLCall(glBindVertexArray(vao));
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

		glDeleteProgram(shader);
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
