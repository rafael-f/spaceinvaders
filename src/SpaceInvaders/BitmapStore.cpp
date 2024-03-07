#include "BitmapStore.h"
#include <assert.h>

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::addBitmap(std::string const& filename)
{
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap;

	auto keyValuePair = bitmapsMap.find(filename);

	if (keyValuePair == bitmapsMap.end())
	{
		bitmapsMap[filename] = Texture("graphics/" + filename + ".png");
	}
}

Texture& BitmapStore::getBitmap(std::string const& filename)
{
	auto& m = m_s_Instance->m_BitmapsMap;

	auto keyValuePair = m.find(filename);

	if (keyValuePair == m.end())
	{
		addBitmap(filename);
		keyValuePair = m.find(filename);
	}
	
	return keyValuePair->second;
}
