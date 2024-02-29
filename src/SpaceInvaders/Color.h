#pragma once

class Color
{
public:
	Color();

	Color(int red, int green, int blue);

	Color(int red, int green, int blue, int alpha);

private:
	int m_Red;
	int m_Green;
	int m_Blue;
	int m_Alpha;
};
