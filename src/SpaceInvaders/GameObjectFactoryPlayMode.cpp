#include "BulletUpdateComponent.h"
#include "GameObjectFactoryPlayMode.h"
#include "InvaderUpdateComponent.h"
#include "PlayerUpdateComponent.h"
#include "RectColliderComponent.h"
#include "StandardGraphicsComponent.h"
#include "TransformComponent.h"
#include <iostream>
#include "ShaderManager.h"
#include "BitmapStore.h"

void GameObjectFactoryPlayMode::buildGameObject(GameObjectBlueprint& bp, std::vector<GameObject>& gameObjects)
{
	GameObject gameObject;

	gameObject.setTag(bp.getName());

	auto it = bp.getComponentList().begin();
	auto end = bp.getComponentList().end();
	for (it; it != end; ++it)
	{
		if (*it == "Transform")
		{
			gameObject.addComponent(std::make_shared<TransformComponent>(bp.getWidth(), bp.getHeight(), Vector2f(bp.getLocationX(), bp.getLocationY())));
		}
		else if (*it == "Player Update")
		{
			gameObject.addComponent(std::make_shared<PlayerUpdateComponent>());
		}
		else if (*it == "Invader Update")
		{
			gameObject.addComponent(std::make_shared<InvaderUpdateComponent>());
		}
		else if (*it == "Bullet Update")
		{
			gameObject.addComponent(std::make_shared<BulletUpdateComponent>());
		}
		else if (*it == "Standard Graphics")
		{
			Sprite sprite = Sprite(ShaderManager::GetShader("sprite"), BitmapStore::getBitmap(bp.getBitmapName()));

			std::shared_ptr<StandardGraphicsComponent> sgp = std::make_shared<StandardGraphicsComponent>(sprite);

			gameObject.addComponent(sgp);

			sgp->initializeGraphics(Vector2f(bp.getWidth(), bp.getHeight()));
		}
	}

	if (bp.getEncompassingRectCollider())
	{
		std::shared_ptr<RectColliderComponent> rcc = std::make_shared<RectColliderComponent>(bp.getEncompassingRectColliderLabel());

		gameObject.addComponent(rcc);

		rcc->setOrMoveCollider(bp.getLocationX(), bp.getLocationY(), bp.getWidth(), bp.getHeight());
	}

	gameObjects.push_back(gameObject);
}
