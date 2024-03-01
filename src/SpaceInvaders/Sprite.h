#pragma once
#include "Color.h"
#include "Drawable.h"
#include "Texture.h"
#include "Vector2f.h"
#include "ShaderProgram.h"

class Sprite : public Drawable
{
public:
	Sprite();

	void setTexture(const Texture& texture);

	Texture* getTexture();

	void setScale(float x, float y);

	void setColor(const Color& color);

	void setPosition(Vector2f position);

	// Inherited via Drawable
	void Draw(const Renderer& renderer) override;

private:
	Texture m_Texture;

	Vector2f m_Scale;

	Color m_Color;

	Vector2f m_Position;

	ShaderProgram m_Shader;

	IndexBuffer m_IndexBuffer;
};
