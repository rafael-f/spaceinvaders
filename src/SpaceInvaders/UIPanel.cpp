#include "Color.h"
#include "UIPanel.h"

UIPanel::UIPanel(Vector2i res, int x, int y, float width, float height,	int alpha, int red, int green, int blue)
{
	m_UIPanel.setFillColor(Color(red, green, blue, alpha));

	m_UIPanel.setSize(Vector2f(width, height));

	m_UIPanel.setPosition(Vector2f(x, y));
}

std::vector<std::shared_ptr<Button>> UIPanel::getButtons()
{
	return m_Buttons;
}

void UIPanel::addButton(float x, float y, int width, int height, Color color, std::string label)
{
	Vector2f position = m_UIPanel.getPosition();

	m_Buttons.push_back(std::make_shared<Button>(Vector2f(x + position.x, y + position.y), width, height, color, label));
}

void UIPanel::draw(RenderWindow& window)
{
	if (!m_Hidden)
	{
		window.draw(&m_UIPanel);

		for (auto it = m_Buttons.begin(); it != m_Buttons.end(); ++it)
		{
			(*it)->draw(window);
		}
	}
}

void UIPanel::show()
{
	m_Hidden = false;
}

void UIPanel::hide()
{
	m_Hidden = true;
}
