#pragma once
#include "Color.h"
#include "Drawable.h"
#include "Vector2f.h"
#include"ShaderManager.h"

// Used to draw a textureless quad
class RectangleShape : public Drawable
{
public:
	explicit RectangleShape();

	void setPosition(Vector2f position);

	Vector2f getPosition();

	void setFillColor(const Color &color);

	void setSize(Vector2f size);

	Vector2f getSize();

	void Draw() override;

private:
	ShaderProgram m_Shader = ShaderManager::GetShader("button");

	VertexArray m_VertexArray;

	Vector2f m_Position;

	Color m_Color;

	Vector2f m_Size;
};
