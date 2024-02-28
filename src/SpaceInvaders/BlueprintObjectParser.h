#pragma once
#include "GameObjectBlueprint.h"
#include <string>

class BlueprintObjectParser
{
private:
	std::string extractStringBetweenTags(const std::string& stringToSearch, const std::string& startTag, const std::string& endTag) const;

public:
	void parseNextObjectForBlueprint(std::ifstream& reader, GameObjectBlueprint& bp) const;
};
