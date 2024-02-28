#include "GameObjectBlueprint.h"

float GameObjectBlueprint::getWidth() const
{
	return m_Width;
}

void GameObjectBlueprint::setWidth(float width)
{
	m_Width = width;
}

float GameObjectBlueprint::getHeight() const
{
	return m_Height;
}

void GameObjectBlueprint::setHeight(float height)
{
	m_Height = height;
}

float GameObjectBlueprint::getLocationX() const
{
	return m_LocationX;
}

void GameObjectBlueprint::setLocationX(float locationX)
{
	m_LocationX = locationX;
}

float GameObjectBlueprint::getLocationY() const
{
	return m_LocationY;
}

void GameObjectBlueprint::setLocationY(float locationY)
{
	m_LocationY = locationY;
}

void GameObjectBlueprint::setName(const std::string& name)
{
	m_Name = "" + name;
}

std::string GameObjectBlueprint::getName() const
{
	return m_Name;
}

std::vector<std::string>& GameObjectBlueprint::getComponentList()
{
	return m_ComponentList;
}

void GameObjectBlueprint::addToComponentList(const std::string& newComponent)
{
	m_ComponentList.push_back(newComponent);
}

std::string GameObjectBlueprint::getBitmapName() const
{
	return m_BitmapName;
}

void GameObjectBlueprint::setBitmapName(const std::string& bitmapName)
{
	m_BitmapName = "" + bitmapName;
}

std::string GameObjectBlueprint::getEncompassingRectColliderLabel() const
{
	return m_EncompassingRectColliderLabel;
}

bool GameObjectBlueprint::getEncompassingRectCollider() const
{
	return m_EncompassingRectCollider;
}

void GameObjectBlueprint::setEncompassingRectCollider(const std::string& label)
{
	m_EncompassingRectCollider = true;
	m_EncompassingRectColliderLabel = "" + label;
}
