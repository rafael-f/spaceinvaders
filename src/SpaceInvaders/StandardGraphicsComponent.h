#pragma once
#include "Component.h"
#include "GraphicsComponent.h"
#include "RenderWindow.h"
#include "Sprite.h"
#include <string>

class Component;

class StandardGraphicsComponent : public GraphicsComponent
{
private:
	Sprite m_Sprite;
	std::string m_SpecificType = "standard";

public:
	std::string Component::getSpecificType()
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self)
	{
	}

	void draw(RenderWindow& window, std::shared_ptr<TransformComponent> t) override;

	void initializeGraphics(std::string bitmapName, Vector2f objectSize) override;
};
