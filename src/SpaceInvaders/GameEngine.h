#pragma once
#include "ScreenManager.h"
//#include "SoundEngine.h"
#include <Windows.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vector2i.h"

class GameEngine
{
private:
	//Clock m_Clock;

	//Time m_DT;

	GLFWwindow* m_Window;

	unique_ptr<ScreenManager> m_ScreenManager;

	float m_FPS = 0;

	Vector2i m_Resolution;

	void handleInput();

	void update();

	void draw(const unsigned int& shader, const unsigned int& location, const float& r);

public:
	//SoundEngine m_SoundEngine;

	GameEngine();

	void run();
};
