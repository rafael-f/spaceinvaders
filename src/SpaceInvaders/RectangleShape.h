#pragma once
#include "Color.h"
#include "Drawable.h"
#include "Vector2f.h"

class RectangleShape : public Drawable
{
public:
	void setPosition(Vector2f position);

	void setFillColor(Color color);

	void setSize(Vector2f size);
};
