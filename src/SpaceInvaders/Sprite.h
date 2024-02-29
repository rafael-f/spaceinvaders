#pragma once
#include "Color.h"
#include "Drawable.h"
#include "Texture.h"
#include "Vector2f.h"

class Sprite : public Drawable
{
public:
	void setTexture(const Texture& texture);

	Texture* getTexture();

	void setScale(float x, float y);

	void setColor(const Color& color);

	void setPosition(Vector2f position);

private:
	Texture m_Texture;

	Vector2f m_Scale;

	Color m_Color;

	Vector2f m_Position;
};
