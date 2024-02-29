#pragma once
#include "Time.h"
#include <chrono>

class Clock
{
public:
	Clock();

	Time getElapsedTime() const;

	Time restart();

private:
	long long m_Milliseconds;

	long long getCurrentTimeMilliseconds() const;
};
