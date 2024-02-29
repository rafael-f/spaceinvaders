#include "Time.h"

Time::Time(float microseconds)
	:m_Milliseconds(microseconds)
{
}

float Time::asMilliseconds() const
{
	return m_Milliseconds;
}

float Time::asSeconds() const
{
	return m_Milliseconds / 1000;
}
