#pragma once
#include "Component.h"
#include "FloatRect.h"
#include "GameObjectSharer.h"
#include "GraphicsComponent.h"
#include "RenderWindow.h"
#include "UpdateComponent.h"
#include <memory>
#include <string>
#include <vector>

class GameObject
{
private:
	std::vector<std::shared_ptr<Component>> m_Components;

	std::string m_Tag;

	bool m_Active = false;
	int m_NumberUpdateComponents = 0;
	bool m_HasUpdateComponent = false;
	int m_FirstUpdateComponentLocation = -1;
	int m_GraphicsComponentLocation = -1;
	bool m_HasGraphicsComponent = false;
	int m_TransformComponentLocation = -1;
	int m_NumberRectColliderComponents = 0;
	int m_FirstRectColliderComponentLocation = -1;
	bool m_HasCollider = false;

public:
	void update(float fps);

	void draw(RenderWindow& window);

	void addComponent(std::shared_ptr<Component> component);

	void setActive();

	void setInactive();

	bool isActive();

	void setTag(const std::string& tag);

	std::string getTag();

	void start(GameObjectSharer* gos);

	// Slow only use in init and start
	std::shared_ptr<Component> getComponentByTypeAndSpecificType(std::string type, std::string specificType);

	FloatRect& getEncompassingRectCollider();

	bool hasCollider();

	bool hasUpdateComponent();

	std::string getEncompassingRectColliderTag();

	std::shared_ptr<GraphicsComponent> getGraphicsComponent();

	std::shared_ptr<TransformComponent> getTransformComponent();

	std::shared_ptr<UpdateComponent> getFirstUpdateComponent();
};
