#pragma once
#include "Renderer.h"

class Drawable
{
public:
	virtual void Draw(const Renderer& renderer) = 0;

	virtual ~Drawable() = default;
};
