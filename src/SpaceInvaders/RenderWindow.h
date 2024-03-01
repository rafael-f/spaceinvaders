#pragma once
#include "Drawable.h"
#include "Event.h"
#include "Renderer.h"
#include "Vector2f.h"
#include "Vector2i.h"
#include "View.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class RenderWindow
{
public:
	RenderWindow();

	void draw(Drawable* drawable);

	Vector2f mapPixelToCoords(Vector2i pixel, const View& view);

	void setView(View view);

	bool pollEvent(Event event);

	void close();

	Vector2i getResolution() const;

	GLFWwindow* getGLFWwindow();

	void clear() const;

	bool shouldClose();

private:
	Vector2i m_Resolution;

	GLFWwindow* m_Window;

	Renderer m_Renderer;
};
