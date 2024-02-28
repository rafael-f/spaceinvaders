#pragma once
#include "Time.h"

class Clock
{
public:
	Time getElapsedTime();

	void restart();
};
