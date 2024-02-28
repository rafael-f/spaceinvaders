#pragma once
#include "Vector2f.h"
#include "FloatRect.h"
#include "Vector2i.h"

class View
{
public:
	void setSize(Vector2f size);

	void setSize(int x, int y);

	void setCenter(int x, int y);

	void setCenter(Vector2f center);

	void setViewport(FloatRect viewport);

	Vector2i getSize();
};
