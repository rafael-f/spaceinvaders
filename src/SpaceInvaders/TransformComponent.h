#pragma once
#include "Component.h"
#include "Vector2f.h"

class Component;

class TransformComponent : public Component
{
private:
	const std::string m_Type = "transform";
	Vector2f m_Location;
	float m_Height;
	float m_Width;

public:
	TransformComponent(float width, float height, Vector2f location);

	Vector2f& getLocation();

	Vector2f getSize() const;

	std::string Component::getType()
	{
		return m_Type;
	}

	std::string Component::getSpecificType()
	{
		return m_Type;
	}

	void Component::disableComponent() {}

	void Component::enableComponent() {}

	bool Component::enabled()
	{
		return false;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self)
	{}
};
