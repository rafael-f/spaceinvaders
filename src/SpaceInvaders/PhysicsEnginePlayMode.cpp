#include "DevelopState.h"
#include "PhysicsEnginePlayMode.h"
#include <iostream>
#include "SoundEngine.h"
#include "WorldState.h"
#include "InvaderUpdateComponent.h"
#include "BulletUpdateComponent.h"
#include "FloatRect.h"

void PhysicsEnginePlayMode::detectInvaderCollisions(
	std::vector<GameObject>& objects,
	const std::vector<int>& bulletPositions)
{
	Vector2f offScreen(-1, -1);

	auto invaderIt = objects.begin();
	auto invaderEnd = objects.end();
	for (invaderIt; invaderIt != invaderEnd; ++invaderIt)
	{
		if (!(*invaderIt).isActive() || (*invaderIt).getTag() != "invader")
		{
			continue;
		}

		auto bulletIt = objects.begin();

		// Jump to the first bullet
		advance(bulletIt, bulletPositions[0]);
		auto bulletEnd = objects.end();
		for (bulletIt; bulletIt != bulletEnd; ++bulletIt)
		{
			bool bulletBelongsToPlayer = (*bulletIt).getTag() == "bullet" && std::static_pointer_cast<BulletUpdateComponent>((*bulletIt).getFirstUpdateComponent())->m_BelongsToPlayer;
			if (!bulletBelongsToPlayer)
			{
				continue;
			}

			FloatRect innvaderRect = (*invaderIt).getEncompassingRectCollider();
			FloatRect bulletRect = (*bulletIt).getEncompassingRectCollider();

			bool bulletHittingInvader = innvaderRect.intersects(bulletRect);

			if (bulletHittingInvader)
			{
				SoundEngine::playInvaderExplode();

				(*invaderIt).getTransformComponent()->getLocation() = offScreen;

				(*bulletIt).getTransformComponent()->getLocation() = offScreen;

				WorldState::SCORE++;

				WorldState::NUM_INVADERS--;

				(*invaderIt).setInactive();
			}
		}
	}
}

void PhysicsEnginePlayMode::detectPlayerCollisionsAndInvaderDirection(std::vector<GameObject>& objects, const std::vector<int>& bulletPositions)
{
	Vector2f offScreen(-1, -1);

	FloatRect playerCollider = m_Player->getEncompassingRectCollider();

	std::shared_ptr<TransformComponent> playerTransform = m_Player->getTransformComponent();

	Vector2f playerLocation = playerTransform->getLocation();

	auto it3 = objects.begin();
	auto end3 = objects.end();
	for (it3; it3 != end3; ++it3)
	{
		if ((*it3).isActive() && (*it3).hasCollider() && (*it3).getTag() != "Player")
		{
			// Get a reference to all the parts of
			// the current game object we might need
			FloatRect currentCollider = (*it3).getEncompassingRectCollider();

			// Detect collisions between objects
			// with the player
			if (currentCollider.intersects(playerCollider))
			{
				if ((*it3).getTag() == "bullet" && !std::static_pointer_cast<BulletUpdateComponent>((*it3).getFirstUpdateComponent())->m_BelongsToPlayer)
				{
					SoundEngine::playPlayerExplode();

					WorldState::LIVES--;

					(*it3).getTransformComponent()->getLocation() = offScreen;
				}

				if ((*it3).getTag() == "invader")
				{
					SoundEngine::playPlayerExplode();
					SoundEngine::playInvaderExplode();

					WorldState::LIVES--;

					(*it3).getTransformComponent()->getLocation() = offScreen;

					WorldState::SCORE++;
					(*it3).setInactive();
				}
			}

			std::shared_ptr<TransformComponent>currentTransform = (*it3).getTransformComponent();

			Vector2f currentLocation = currentTransform->getLocation();

			std::string currentTag = (*it3).getTag();

			Vector2f currentSize = currentTransform->getSize();

			// Handle the direction and descent
			// of the invaders
			if (currentTag == "invader")
			{
				// This is an invader
				if (!m_NeedToDropDownAndReverse &&
					!m_InvaderHitWallThisFrame)
				{
					// Currently no need to dropdown
					// and reverse from previous frame
					// or any hits this frame
					if (currentLocation.x >= WorldState::WORLD_WIDTH - currentSize.x)
					{
						// The invader is passed its
						// furthest right position
						if (std::static_pointer_cast<InvaderUpdateComponent>((*it3).getFirstUpdateComponent())->isMovingRight())
						{
							// The invader is travelling
							// right so set a flag that
							// an invader has collided

							m_InvaderHitWallThisFrame = true;
						}
					}
					else if (currentLocation.x < 0)
					{
						// The invader is past its furthest
						// left position
						if (!std::static_pointer_cast<InvaderUpdateComponent>((*it3).getFirstUpdateComponent())->isMovingRight())
						{
							// The invader is travelling
							// left so set a flag that an
							// invader has collided
							m_InvaderHitWallThisFrame = true;
						}
					}
				}
				else if (m_NeedToDropDownAndReverse && !m_InvaderHitWallPreviousFrame)
				{
					// Drop down and reverse has been set
					if ((*it3).hasUpdateComponent())
					{
						// Drop down and reverse
						std::static_pointer_cast<InvaderUpdateComponent>((*it3).getFirstUpdateComponent())->dropDownAndReverse();
					}
				}
			}
		}
	}
}

void PhysicsEnginePlayMode::handleInvaderDirection()
{
	if (m_InvaderHitWallThisFrame)
	{
		m_NeedToDropDownAndReverse = true;
		m_InvaderHitWallThisFrame = false;
	}
	else
	{
		m_NeedToDropDownAndReverse = false;
	}
}

void PhysicsEnginePlayMode::initilize(GameObjectSharer& gos)
{
	m_PUC = std::static_pointer_cast<PlayerUpdateComponent>(gos.findFirstObjectWithTag("Player").getComponentByTypeAndSpecificType("update", "player"));

	m_Player = &gos.findFirstObjectWithTag("Player");
}

void PhysicsEnginePlayMode::detectCollisions(std::vector<GameObject>& objects, const std::vector<int>& bulletPositions)
{
	detectInvaderCollisions(objects, bulletPositions);

	detectPlayerCollisionsAndInvaderDirection(objects, bulletPositions);

	handleInvaderDirection();
}
