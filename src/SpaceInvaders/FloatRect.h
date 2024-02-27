#pragma once
#include "Vector2f.h"

class FloatRect
{
public:
	explicit FloatRect(Vector2f position, Vector2f size);

private:
	Vector2f m_Position;
	Vector2f m_Size;
};
