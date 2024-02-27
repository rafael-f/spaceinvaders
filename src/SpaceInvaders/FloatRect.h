#pragma once
#include "Vector2f.h"

class FloatRect
{
public:
	FloatRect() = default;

	explicit FloatRect(Vector2f position, Vector2f size);

	bool intersects(FloatRect other);

private:
	Vector2f m_Position;
	Vector2f m_Size;
};
