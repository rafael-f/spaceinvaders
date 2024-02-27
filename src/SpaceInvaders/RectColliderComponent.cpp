#include "RectColliderComponent.h"

RectColliderComponent::RectColliderComponent(std::string name)
{
	m_Tag = "" + name;
}

std::string RectColliderComponent::getColliderTag()
{
	return m_Tag;
}

void RectColliderComponent::setOrMoveCollider(float x, float y, float width, float height)
{
	
	m_Collider.x = x;
	m_Collider.y = y;
	m_Collider.z = width;
	m_Collider.w = height;
}

FloatRect& RectColliderComponent::getColliderRectF()
{
	return m_Collider;
}
