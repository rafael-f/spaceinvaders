#pragma once
#include "Texture.h"
#include <map>
#include <string>

class BitmapStore
{
private:
	std::map<std::string, Texture> m_BitmapsMap;

	static BitmapStore* m_s_Instance;

public:
	BitmapStore();

	static Texture& getBitmap(std::string const& filename);

	static void addBitmap(std::string const& filename);
};
