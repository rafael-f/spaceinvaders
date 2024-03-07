#include "ScreenManager.h"
#include "ShaderManager.h"
#include "BitmapStore.h"
#include <STB/stb_image.h>

ScreenManager::ScreenManager(Vector2i res)
{
	//stbi_set_flip_vertically_on_load(true);
	Sprite gameBackground = Sprite(ShaderManager::GetShader("sprite"), BitmapStore::getBitmap("background"));

	gameBackground.setSize(res.x, res.y);

	m_Screens["Game"] = std::make_unique<GameScreen>(this, res, gameBackground);
	m_Screens["Select"] = std::make_unique<SelectScreen>(this, res, gameBackground);
}

void ScreenManager::handleInput(RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->handleInput(window);
}

void ScreenManager::update(float fps)
{
	m_Screens[m_CurrentScreen]->update(fps);
}

void ScreenManager::draw(RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->draw(window);
}
