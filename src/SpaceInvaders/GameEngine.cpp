#include "GameEngine.h"
#include <Windows.h>
#include <cstdlib>
#include <string>
#include <fstream>

#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		//todo cout error function file line
		return false;
	}

	return true;
}

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

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	unsigned int ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	std::string vertexShader = ReadFile("VertexShader.hlsl");
	std::string fragmentShader = ReadFile("PixelShader.hlsl");

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	while (!glfwWindowShouldClose(m_Window))
	{
	//	m_DT = m_Clock.restart();
	//	m_FPS = m_DT.asSeconds();
	//	handleInput();
	//	update();
		draw();
	}

	glDeleteProgram(shader);

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

	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

	/* Swap front and back buffers */
	glfwSwapBuffers(m_Window);

	/* Poll for and process events */
	glfwPollEvents();

	//m_Window.clear(Color::Black);
	//m_ScreenManager->draw(m_Window);
	//m_Window.display();
}
