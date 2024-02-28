#pragma once
#include "ColliderComponent.h"
#include "FloatRect.h"

class RectColliderComponent : public ColliderComponent
{
private:
	std::string m_SpecificType = "rect";
	FloatRect m_Collider;
	std::string m_Tag = "";

public:
	explicit RectColliderComponent(std::string name);

	std::string getColliderTag();

	void setOrMoveCollider(float x, float y, float width, float height);

	FloatRect& getColliderRectF();

	std::string getSpecificType() override
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self) {}
};
