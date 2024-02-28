#include "Sprite.h"

Sprite::Sprite()
    : m_Texture("todo") // todo
{
}

void Sprite::setTexture(const Texture& texture)
{
    m_Texture = texture;
}

Texture* Sprite::getTexture()
{
    return &m_Texture; // todo verify how good or bad this is
}

void Sprite::setScale(float x, float y)
{
}

void Sprite::setColor(Color color)
{
}

void Sprite::setPosition(Vector2f position)
{
}
