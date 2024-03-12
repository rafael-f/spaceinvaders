#pragma once
#include "Color.h"
#include "Drawable.h"
#include "Texture.h"
#include "Vector2f.h"
#include "ShaderProgram.h"

// Quad with texture
class Sprite : public Drawable
{
public:
	explicit Sprite(ShaderProgram& shader, Texture& texture);

	Texture* getTexture();

	void setSize(float x, float y);

	void setColor(const Color& color);

	void setPosition(Vector2f position);

	void Draw() override;

private:
	ShaderProgram& m_Shader;
	
	Texture& m_Texture;

	Vector2f m_Size = Vector2f(100.0f, 100.0f);

	Color m_Color;

	Vector2f m_Position;

	VertexArray m_VertexArray;
};
