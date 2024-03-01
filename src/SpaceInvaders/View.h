#pragma once
#include "Vector2f.h"
#include "FloatRect.h"
#include "Vector2i.h"

class View
{
public:
	void setSize(Vector2f size);

	void setSize(float x, float y);

	void setCenter(float x, float y);

	void setCenter(Vector2f center);

	void setViewport(const FloatRect& viewport);

	Vector2f getSize() const;

private:
	Vector2f m_Size = Vector2f(1.0f, 1.0f);
	Vector2f m_Center = Vector2f(0.0f, 0.0f);
	FloatRect m_Viewport = FloatRect(0.0f, 0.0f, 1.0f, 1.0f);
};
