#include "StandardGraphicsComponent.h"
#include "BitmapStore.h"
#include <iostream>
#include "Color.h"

void StandardGraphicsComponent::initializeGraphics(Vector2f objectSize)
{
	m_Sprite.setSize(objectSize.x, objectSize.y);

	m_Sprite.setColor(Color(0, 255, 0));
}

StandardGraphicsComponent::StandardGraphicsComponent(const Sprite& sprite)
	:m_Sprite(sprite)
{
}

void StandardGraphicsComponent::draw(RenderWindow& window, std::shared_ptr<TransformComponent> t)
{
	m_Sprite.setPosition(t->getLocation());
	window.draw(&m_Sprite);
}
