#pragma once
//#include "ScreenManager.h"
//#include "SoundEngine.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vector2f.h"

class GameEngine
{
private:
	//Clock m_Clock;

	//Time m_DT;

	GLFWwindow* m_Window;

	//unique_ptr<ScreenManager> m_ScreenManager;

	float m_FPS = 0;

	Vector2f m_Resolution;

	void handleInput();

	void update();

	void draw();

public:
	//SoundEngine m_SoundEngine;

	GameEngine();

	void run();
};
