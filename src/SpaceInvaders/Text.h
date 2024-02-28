#pragma once
#include "Color.h"
#include "Drawable.h"
#include "Font.h"
#include "Vector2f.h"
#include <string>

class Text : public Drawable
{
public:
	void setCharacterSize(float size);

	void setString(std::string text);

	void setFont(Font font);

	void setPosition(Vector2f position);

	void setFillColor(Color color);
};
