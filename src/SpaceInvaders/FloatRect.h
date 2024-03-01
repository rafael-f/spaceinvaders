#pragma once
#include "Vector2f.h"

class FloatRect
{
public:
	FloatRect() = default;

	explicit FloatRect(Vector2f position, Vector2f size);

	explicit FloatRect(float positionX, float positionY, float sizeX, float sizeY);

	bool intersects(const FloatRect& other) const;

	bool contains(Vector2f point) const;

	Vector2f getPosition() const;

	Vector2f getSize() const;

	void setValues(float positionX, float positionY, float sizeX, float sizeY);

private:
	Vector2f m_Position;

	Vector2f m_Size;
};
