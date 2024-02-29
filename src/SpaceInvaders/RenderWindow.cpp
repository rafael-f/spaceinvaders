#include "Renderer.h"
#include "RenderWindow.h"
#include <cstdlib>
#include <Windows.h>

RenderWindow::RenderWindow()
{
	m_Resolution.x = GetSystemMetrics(SM_CXSCREEN);
	m_Resolution.y = GetSystemMetrics(SM_CYSCREEN);
	m_Window = glfwCreateWindow(m_Resolution.x, m_Resolution.y, "Space Invaders++", nullptr, nullptr);

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

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void RenderWindow::draw(Drawable drawable)
{

}

Vector2f RenderWindow::mapPixelToCoords(Vector2i pixel, const View& view)
{
	return Vector2f();
}

void RenderWindow::setView(View view)
{

}

bool RenderWindow::pollEvent(Event event)
{
	return false;
}

void RenderWindow::close()
{
	glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
}

Vector2i RenderWindow::getResolution() const
{
	return m_Resolution;
}

GLFWwindow* RenderWindow::getGLFWwindow()
{
	return m_Window;
}

void RenderWindow::clear() const
{
	m_Renderer.Clear();
}

bool RenderWindow::shouldClose()
{
	return glfwWindowShouldClose(m_Window);
}
