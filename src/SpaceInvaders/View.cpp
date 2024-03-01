#include "View.h"

void View::setSize(Vector2f size)
{
    m_Size = size;
}

void View::setSize(float x, float y)
{
    m_Size.x = x;
    m_Size.y = y;
}

void View::setCenter(float x, float y)
{
    m_Center.x = x;
    m_Center.y = y;
}

void View::setCenter(Vector2f center)
{
    m_Center = center;
}

void View::setViewport(const FloatRect& viewport)
{
    m_Viewport = viewport;
}

Vector2f View::getSize() const
{
    return m_Size;
}
