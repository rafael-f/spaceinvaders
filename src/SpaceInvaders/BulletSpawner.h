#pragma once
#include "Vector2f.h"

class BulletSpawner
{
public:
	virtual void spawnBullet(Vector2f spawnLocation, bool forPlayer) = 0;

	virtual ~BulletSpawner() = default;
};
