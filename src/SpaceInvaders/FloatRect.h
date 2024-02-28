#pragma once
#include "Vector2f.h"

class FloatRect
{
public:
	FloatRect() = default;

	explicit FloatRect(Vector2f position, Vector2f size);

	explicit FloatRect(float positionX, float positionY, float sizeX, float sizeY);

	bool intersects(FloatRect other);

	bool contains(Vector2f point);

	float x;
	float y;
	float z;
	float w;

private:
	Vector2f m_Position;
	Vector2f m_Size;
};
