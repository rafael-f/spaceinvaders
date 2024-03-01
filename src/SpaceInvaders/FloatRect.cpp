#include "FloatRect.h"

FloatRect::FloatRect(Vector2f position, Vector2f size)
	:m_Position(position), m_Size(size)
{
}

FloatRect::FloatRect(float positionX, float positionY, float sizeX, float sizeY)
	:m_Position(positionX, positionY), m_Size(sizeX, sizeY)
{
}

bool FloatRect::intersects(const FloatRect& other) const
{
	Vector2f otherPosition = other.getPosition();
	Vector2f otherSize = other.getSize();

	return m_Position.x < otherPosition.x + otherSize.x &&
		m_Position.x + m_Size.x > otherPosition.x &&
		m_Position.y < otherPosition.y + otherSize.y &&
		m_Position.y + m_Size.y > otherPosition.y;
}

bool FloatRect::contains(Vector2f point) const
{
	return point.x >= m_Position.x &&
		point.x <= m_Position.x + m_Size.x &&
		point.y >= m_Position.y &&
		point.y <= m_Position.y + m_Size.y;
}

Vector2f FloatRect::getPosition() const
{
	return m_Position;
}

Vector2f FloatRect::getSize() const
{
	return m_Size;
}

void FloatRect::setValues(float positionX, float positionY, float sizeX, float sizeY)
{
	m_Position.x = positionX;
	m_Position.y = positionY;
	m_Size.x = sizeX;
	m_Size.y = sizeY;
}
