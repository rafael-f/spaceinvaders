#include "Sprite.h"

void Sprite::setTexture(const Texture& texture)
{
    m_Texture = texture;
}

Texture* Sprite::getTexture()
{
    return &m_Texture;
}

void Sprite::setScale(float x, float y)
{
    m_Scale.x = x;
    m_Scale.y = y;
}

void Sprite::setColor(const Color& color)
{
    m_Color = color;
}

void Sprite::setPosition(Vector2f position)
{
    m_Position = position;
}
