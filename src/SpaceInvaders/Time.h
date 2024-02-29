#pragma once

class Time
{
public:
	explicit Time(float milliseconds);

	float asMilliseconds() const;

	float asSeconds() const;

private:
	float m_Milliseconds;
};
