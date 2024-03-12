#pragma once
#include "Drawable.h"
#include "Event.h"
#include "Renderer.h"
#include "Vector2f.h"
#include "Vector2i.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <queue>

class RenderWindow
{
public:
	RenderWindow();

	void draw(Drawable* drawable);

	Vector2f mapPixelToCoords(Vector2i pixel);

	bool pollEvent(Event& event);

	void close();

	Vector2i getResolution() const;

	GLFWwindow* getGLFWwindow();

	void clear() const;

	bool shouldClose();

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	void framebufferSizeCallback(GLFWwindow* window, int width, int height);

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

private:
	Vector2i m_Resolution;

	GLFWwindow* m_Window;

	Renderer m_Renderer;

	std::queue<Event> m_Events;
};
