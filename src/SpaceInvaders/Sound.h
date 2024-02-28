#pragma once
#include "SoundBuffer.h"

class Sound
{
public:
	void setBuffer(SoundBuffer soundBuffer);

	void play();

private:
	SoundBuffer m_SoundBuffer;
};
