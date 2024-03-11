#include "Renderer.h"
#include "RenderWindow.h"
#include <cstdlib>
#include <Windows.h>
#include "Texture.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	GLCall(glViewport(0, 0, width, height));
}

RenderWindow::RenderWindow()
{
	if (!glfwInit())
	{
		std::cout << "Failure initializing glfw." << std::endl;
		std::exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwWindowHint(GLFW_RESIZABLE, false);

	m_Resolution.x = GetSystemMetrics(SM_CXSCREEN);
	m_Resolution.y = GetSystemMetrics(SM_CYSCREEN);
	m_Window = glfwCreateWindow(m_Resolution.x, m_Resolution.y, "Space Invaders++", nullptr, nullptr);

	if (!m_Window)
	{
		std::cout << "Failure initializing Window." << std::endl;
		glfwTerminate();
		std::exit(-1);
	}

	//glfwMaximizeWindow(m_Window);

	glfwSetWindowMonitor(m_Window, glfwGetPrimaryMonitor(), 0, 0, m_Resolution.x, m_Resolution.y, GLFW_DONT_CARE);

	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failure initializing GLEW." << std::endl;
		glfwTerminate();
		std::exit(-1);
	}

	glfwSetFramebufferSizeCallback(m_Window, framebufferSizeCallback);

	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
	{
		// Access instance or non-static members
		RenderWindow* instance = static_cast<RenderWindow*>(glfwGetWindowUserPointer(window));
		instance->mouse_button_callback(window, button, action, mods);
	});

	glfwSetWindowUserPointer(m_Window, this);

	glViewport(0, 0, m_Resolution.x, m_Resolution.y);
	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void RenderWindow::draw(Drawable* drawable)
{
	drawable->Draw();
}

Vector2f RenderWindow::mapPixelToCoords(Vector2i pixel, const View& view)
{
	return Vector2f(pixel.x, pixel.y);
}

void RenderWindow::setView(View view)
{
	//view.setActive();
	//glViewport(0, 0, view.getSize().x, view.getSize().y);
}

bool RenderWindow::pollEvent(Event& event)
{
	if (!m_Events.empty())
	{
		event = m_Events.front();
		m_Events.pop();

		return true;
	}

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

void RenderWindow::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		double xpos;
		double ypos;

		glfwGetCursorPos(window, &xpos, &ypos);

		Event event;
		event.type = Event::MouseButtonReleased;
		event.mousePosition.x = xpos;
		event.mousePosition.y = ypos;

		m_Events.push(event);
	}
}
