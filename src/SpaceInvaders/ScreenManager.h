#pragma once
#include "BitmapStore.h"
#include "GameScreen.h"
#include "LevelManager.h"
#include "ScreenManagerRemoteControl.h"
#include "SelectScreen.h"
#include <iostream>
#include <map>

class ScreenManager : public ScreenManagerRemoteControl
{
private:
	std::map <std::string, std::unique_ptr<Screen>> m_Screens;

	LevelManager m_LevelManager;
protected:
	std::string m_CurrentScreen = "Select";

public:
	BitmapStore m_BS;

	ScreenManager(Vector2i res);

	void update(float fps);
	void draw(GLFWwindow& window);
	void handleInput(GLFWwindow& window);

	void ScreenManagerRemoteControl::SwitchScreens(std::string screenToSwitchTo)
	{
		m_CurrentScreen = "" + screenToSwitchTo;
		m_Screens[m_CurrentScreen]->initialise();
	}

	void ScreenManagerRemoteControl::loadLevelInPlayMode(std::string screenToLoad)
	{
		m_LevelManager.getGameObjects().clear();
		m_LevelManager.
		loadGameObjectsForPlayMode(screenToLoad);
		SwitchScreens("Game");
	}

	std::vector<GameObject>&	ScreenManagerRemoteControl::getGameObjects()
	{
		return m_LevelManager.getGameObjects();
	}

	GameObjectSharer& shareGameObjectSharer()
	{
		return m_LevelManager;
	}
};
