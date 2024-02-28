#pragma once
#include "Event.h"
#include "Vector2f.h"
#include "Vector2i.h"
#include "View.h"
#include "Window.h"

class RenderWindow : public Window
{
public:
	void draw(Drawable drawable);

	Vector2f mapPixelToCoords(Vector2i pixel, const View& view);

	void setView(View view);

	bool pollEvent(Event event);

	void close();
};
