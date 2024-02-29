#pragma once
#include "ScreenManager.h"
#include "SoundEngine.h"
#include "Vector2i.h"
#include "RenderWindow.h"

class GameEngine
{
public:
	GameEngine();

	void run();

private:
	Clock m_Clock;

	Time m_DT = Time(0);

	std::unique_ptr<RenderWindow> m_Window;

	std::unique_ptr<ScreenManager> m_ScreenManager;

	float m_FPS = 0;

	Vector2i m_Resolution;

	void handleInput();

	void update();

	void draw();

	SoundEngine m_SoundEngine;
};
