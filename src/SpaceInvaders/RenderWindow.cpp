#include "Renderer.h"
#include "RenderWindow.h"
#include <cstdlib>
#include <Windows.h>
#include "Texture.h"

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

	glfwMaximizeWindow(m_Window);

	//glfwSetWindowMonitor(m_Window, glfwGetPrimaryMonitor(), 0, 0, m_Resolution.x, m_Resolution.y, GLFW_DONT_CARE);

	glfwMakeContextCurrent(m_Window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failure initializing GLEW." << std::endl;
		glfwTerminate();
		std::exit(-1);
	}

	glfwSetWindowUserPointer(m_Window, this);

	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			RenderWindow* instance = static_cast<RenderWindow*>(glfwGetWindowUserPointer(window));
			instance->framebufferSizeCallback(window, width, height);
		});

	glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			RenderWindow* instance = static_cast<RenderWindow*>(glfwGetWindowUserPointer(window));
			instance->mouse_button_callback(window, button, action, mods);
		});

	glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mode)
		{
			RenderWindow* instance = static_cast<RenderWindow*>(glfwGetWindowUserPointer(window));
			instance->key_callback(window, key, scancode, action, mode);
		});

	int windowX, windowY;
	glfwGetWindowPos(m_Window, &windowX, &windowY);

	//int windowWidth, windowHeight;
	//glfwGetWindowSize(window, &windowWidth, &windowHeight);

	glViewport(-windowX, -windowY, m_Resolution.x, m_Resolution.y); // todo ?

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void RenderWindow::draw(Drawable* drawable)
{
	drawable->Draw();
}

Vector2f RenderWindow::mapPixelToCoords(Vector2i pixel)
{
	return Vector2f(pixel.x, pixel.y); // todo
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

		//int windowWidth, windowHeight;
		//glfwGetWindowSize(window, &windowWidth, &windowHeight);

		//int windowX, windowY;
		//glfwGetWindowPos(window, &windowX, &windowY);

		double mouseX = xpos /* + windowX*/;
		double mouseY = ypos /* + windowY*/;

		Event event;
		event.type = Event::MouseButtonReleased;
		event.mousePosition.x = mouseX;
		event.mousePosition.y = mouseY;

		m_Events.push(event);
	}
}

void RenderWindow::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	GLCall(glViewport(0, 0, width, height));
}

void RenderWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	Event event;

	if (action == GLFW_PRESS)
	{
		event.type = Event::KeyPressed;
	}
	else if(action == GLFW_RELEASE)
	{
		event.type = Event::KeyReleased;
	}

	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		event.key.code = Keyboard::Escape;
		break;
	case GLFW_KEY_LEFT:
		event.key.code = Keyboard::Left;
		break;
	case GLFW_KEY_RIGHT:
		event.key.code = Keyboard::Right;
		break;
	case GLFW_KEY_UP:
		event.key.code = Keyboard::Up;
		break;
	case GLFW_KEY_DOWN:
		event.key.code = Keyboard::Down;
		break;
	case GLFW_KEY_SPACE:
		event.key.code = Keyboard::Space;
		break;
	default:
		return;
	}

	m_Events.push(event);
}
