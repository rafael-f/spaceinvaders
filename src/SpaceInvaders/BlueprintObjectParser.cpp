#include "BlueprintObjectParser.h"
#include "ObjectTags.h"
#include <iostream>
#include <fstream>

void BlueprintObjectParser::parseNextObjectForBlueprint(std::ifstream& reader, GameObjectBlueprint& bp) const
{
	std::string lineFromFile;
	std::string value = "";

	while (getline(reader, lineFromFile))
	{
		if (lineFromFile.find(ObjectTags::COMPONENT) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::COMPONENT, ObjectTags::COMPONENT_END);
			bp.addToComponentList(value);
		}
		else if (lineFromFile.find(ObjectTags::NAME) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::NAME, ObjectTags::NAME_END);
			bp.setName(value);
		}
		else if (lineFromFile.find(ObjectTags::WIDTH) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::WIDTH, ObjectTags::WIDTH_END);
			bp.setWidth(stof(value));
		}
		else if (lineFromFile.find(ObjectTags::HEIGHT) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::HEIGHT, ObjectTags::HEIGHT_END);
			bp.setHeight(stof(value));
		}
		else if (lineFromFile.find(ObjectTags::LOCATION_X) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::LOCATION_X, ObjectTags::LOCATION_X_END);
			bp.setLocationX(stof(value));
		}
		else if (lineFromFile.find(ObjectTags::LOCATION_Y) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::LOCATION_Y, ObjectTags::LOCATION_Y_END);
			bp.setLocationY(stof(value));
		}
		else if (lineFromFile.find(ObjectTags::BITMAP_NAME) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::BITMAP_NAME, ObjectTags::BITMAP_NAME_END);
			bp.setBitmapName(value);
		}
		else if (lineFromFile.find(ObjectTags::ENCOMPASSING_RECT_COLLIDER) != std::string::npos)
		{
			value = extractStringBetweenTags(lineFromFile, ObjectTags::ENCOMPASSING_RECT_COLLIDER, ObjectTags::ENCOMPASSING_RECT_COLLIDER_END);
			bp.setEncompassingRectCollider(value);
		}
		else if (lineFromFile.find(ObjectTags::END_OF_OBJECT) != std::string::npos)
		{
			return;
		}
	}
}

std::string BlueprintObjectParser::extractStringBetweenTags(const std::string& stringToSearch, const std::string& startTag, const std::string& endTag) const
{
	int start = startTag.length();
	int count = stringToSearch.length() - startTag.length() - endTag.length();
	std::string stringBetweenTags = stringToSearch.substr(start, count);
	return stringBetweenTags;
}
