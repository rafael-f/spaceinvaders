#include "Color.h"

Color::Color(int red, int green, int blue)
	:m_Red(red), m_Green(green), m_Blue(blue), m_Alpha(1)
{

}

Color::Color(int red, int green, int blue, int alpha)
	:m_Red(red), m_Green(green), m_Blue(blue), m_Alpha(alpha)
{
}
