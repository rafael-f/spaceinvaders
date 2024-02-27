#pragma once
#include "GameObject.h"
#include "GameObjectSharer.h"
#include <string>
#include <vector>

class LevelManager : public GameObjectSharer
{
private:
	std::vector<GameObject> m_GameObjects;

	const std::string WORLD_FOLDER = "world";
	const std::string SLASH = "/";

	void runStartPhase();
	void activateAllGameObjects();

public:
	virtual ~LevelManager() = default;

	std::vector<GameObject>& getGameObjects();

	void loadGameObjectsForPlayMode(const std::string& screenToLoad);

	std::vector<GameObject>& GameObjectSharer::getGameObjectsWithGOS()
	{
		return m_GameObjects;
	}

	GameObject& GameObjectSharer::findFirstObjectWithTag(std::string tag)
	{
		auto it = m_GameObjects.begin();
		auto end = m_GameObjects.end();
		for (it; it != end; ++it)
		{
			if ((*it).getTag() == tag)
			{
				return (*it);
			}
		}

#ifdef debuggingErrors
		cout <<
			"LevelManager.h findFirstGameObjectWithTag() "
			<< "- TAG NOT FOUND ERROR!"
			<< endl;
#endif

		return m_GameObjects[0];
	}
};
