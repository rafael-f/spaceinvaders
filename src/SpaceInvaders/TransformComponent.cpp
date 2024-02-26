#include "TransformComponent.h"

TransformComponent::TransformComponent(float width, float height, Vector2f location)
	: m_Location(location), m_Height(height), m_Width(width)
{
}

Vector2f& TransformComponent::getLocation()
{
	return m_Location;
}

Vector2f TransformComponent::getSize() const
{
	return Vector2f(m_Width, m_Height);
}
