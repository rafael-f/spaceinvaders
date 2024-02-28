#include "FloatRect.h"

FloatRect::FloatRect(Vector2f position, Vector2f size)
	:m_Position(position), m_Size(size)
{

}

FloatRect::FloatRect(float positionX, float positionY, float sizeX, float sizeY)
{
}

bool FloatRect::intersects(FloatRect other)
{
	return false;
}

bool FloatRect::contains(Vector2f point)
{
	return false;
}
