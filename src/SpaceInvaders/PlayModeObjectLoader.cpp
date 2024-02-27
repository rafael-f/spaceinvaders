#include "PlayModeObjectLoader.h"
#include "ObjectTags.h"
#include <iostream>
#include <fstream>

void PlayModeObjectLoader::loadGameObjectsForPlayMode(std::string pathToFile, std::vector<GameObject>& gameObjects)
{
	std::ifstream reader(pathToFile);

	std::string lineFromFile;

	std::string value = "";

	while (getline(reader, lineFromFile))
	{
		if (lineFromFile.find(ObjectTags::START_OF_OBJECT) != std::string::npos)
		{
			GameObjectBlueprint bp;

			m_BOP.parseNextObjectForBlueprint(reader, bp);

			m_GameObjectFactoryPlayMode.buildGameObject(bp, gameObjects);
		}
	}
}
