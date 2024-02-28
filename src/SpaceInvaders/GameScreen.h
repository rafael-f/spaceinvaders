#pragma once
#include "BulletSpawner.h"
#include "Clock.h"
#include "GameInputHandler.h"
#include "GameOverInputHandler.h"
#include "PhysicsEnginePlayMode.h"
#include "Screen.h"
#include "Sprite.h"
#include "Time.h"

class GameScreen : public Screen, public BulletSpawner
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	std::shared_ptr<GameInputHandler> m_GIH;
	PhysicsEnginePlayMode m_PhysicsEnginePlayMode;

	int m_NumberInvadersInWorldFile = 0;

	std::vector<int> m_BulletObjectLocations;

	int m_NextBullet = 0;
	bool m_WaitingToSpawnBulletForPlayer = false;
	bool m_WaitingToSpawnBulletForInvader = false;

	Vector2f m_PlayerBulletSpawnLocation;
	Vector2f m_InvaderBulletSpawnLocation;

	Clock m_BulletClock;

	Texture m_BackgroundTexture;
	Sprite m_BackgroundSprite;

public:
	static bool m_GameOver;

	GameScreen(ScreenManagerRemoteControl* smrc, Vector2i res);

	void initialise() override;

	void virtual update(float fps);
	void virtual draw(RenderWindow& window);

	BulletSpawner* getBulletSpawner();

	void BulletSpawner::spawnBullet(Vector2f spawnLocation, bool forPlayer)
	{
		if (forPlayer)
		{
			Time elapsedTime = m_BulletClock.getElapsedTime();

			if (elapsedTime.asMilliseconds() > 500)
			{
				m_PlayerBulletSpawnLocation.x = spawnLocation.x;
				m_PlayerBulletSpawnLocation.y = spawnLocation.y;
				m_WaitingToSpawnBulletForPlayer = true;
				m_BulletClock.restart();
			}
		}
		else
		{
			m_InvaderBulletSpawnLocation.x = spawnLocation.x;
			m_InvaderBulletSpawnLocation.y = spawnLocation.y;
			m_WaitingToSpawnBulletForInvader = true;
		}
	}
};
