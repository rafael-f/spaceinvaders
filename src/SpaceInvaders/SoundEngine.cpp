#include <assert.h>
#include "SoundEngine.h"

SoundEngine* SoundEngine::m_s_Instance = nullptr;

SoundEngine::SoundEngine()
{
	assert(m_s_Instance == nullptr);

	m_s_Instance = this;

	irrklangEngine = irrklang::createIrrKlangDevice();
	irrklangEngine->setSoundVolume(0.15f);
}

void SoundEngine::playShoot()
{
	m_s_Instance->irrklangEngine->play2D("sound/shoot.ogg", false);
}

void SoundEngine::playPlayerExplode()
{
	m_s_Instance->irrklangEngine->play2D("sound/playerexplode.ogg", false);
}

void SoundEngine::playInvaderExplode()
{
	m_s_Instance->irrklangEngine->play2D("sound/invaderexplode.ogg", false);
}

void SoundEngine::playClick()
{
	m_s_Instance->irrklangEngine->play2D("sound/click.ogg", false);
}
