#pragma once
#include "Screen.h"
#include "Texture.h"
#include "Sprite.h"

class SelectScreen : public Screen
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	Texture m_BackgroundTexture;
	Sprite m_BackgroundSprite;

public:
	SelectScreen(ScreenManagerRemoteControl* smrc, Vector2i res);
	void virtual draw(RenderWindow& window);
};
