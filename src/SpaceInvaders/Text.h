#pragma once
#include "Color.h"
#include "Drawable.h"
#include "Font.h"
#include "Vector2f.h"
#include <string>
#include "ShaderManager.h"

class Text : public Drawable
{
public:
	Text();

	void setCharacterSize(float size);

	void setString(std::string text);

	void setFont(Font font);

	void setPosition(Vector2f position);

	void setFillColor(Color color);

	// Inherited via Drawable
	void Draw() override;

private:
	ShaderProgram m_Shader = ShaderManager::GetShader("text");

	VertexArray m_VertexArray;

	Color m_Color;

	std::string m_Text;

	Vector2f m_Position;

	float m_Size;

	VertexBuffer m_VertexBuffer;

	Font m_Font;
};
