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

	void setActive();

private:
	// The size of the view determines the size of it's content.
	Vector2f m_Size = Vector2f(1000.0f, 1000.0f);

	// The center of the view determines the relative center of where it's content will be aligned.
	Vector2f m_Center = Vector2f(500.0f, 500.0f);

	// The viewport of the view determines where the view will be drawn inside the window.
	FloatRect m_Viewport = FloatRect(0.0f, 0.0f, 1.0f, 1.0f);
};
