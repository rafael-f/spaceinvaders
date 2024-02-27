#include "FloatRect.h"

FloatRect::FloatRect(Vector2f position, Vector2f size)
	:m_Position(position), m_Size(size)
{

}

bool FloatRect::intersects(FloatRect other)
{
	return false;
}
