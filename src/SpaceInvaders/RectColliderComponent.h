#pragma once
#include "ColliderComponent.h"
#include <glm/glm.hpp>

class RectColliderComponent : public ColliderComponent
{
private:
	std::string m_SpecificType = "rect";
	glm::vec4 m_Collider;
	std::string m_Tag = "";

public:
	explicit RectColliderComponent(std::string name);

	std::string getColliderTag();

	void setOrMoveCollider(float x, float y, float width, float height);

	glm::vec4& getColliderRectF();

	std::string getSpecificType() override
	{
		return m_SpecificType;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self) {}
};
