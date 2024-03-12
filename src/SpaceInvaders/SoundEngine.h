#pragma once
#include <irrKlang.h>

class SoundEngine
{
public:
	SoundEngine();

	static void playShoot();
	static void playPlayerExplode();
	static void playInvaderExplode();
	static void playClick();

	static SoundEngine* m_s_Instance;

private:
	irrklang::ISoundEngine* irrklangEngine;
};
